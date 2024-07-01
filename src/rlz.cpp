#include "rlz.h"

RLZ::RLZ(std::string ref_file, std::string seq_file)
    : ref_file(ref_file), seq_file(seq_file) {
    load_file_to_vector(ref_file, ref_vec);
    load_file_to_vector(seq_file, seq_vec);
}

void RLZ::load_file_to_vector(const std::string& file_path,
                              seqan3::bitpacked_sequence<seqan3::dna5>& vec) {
    std::ifstream file(file_path);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + file_path);
    }

    std::string line;
    while (std::getline(file, line)) {
        for (char c : line) {
            vec.push_back(seqan3::assign_char_to(c, seqan3::dna5{}));
        }
    }
}

void RLZ::compress() {
    if (!compressed.empty()) {
        compressed.clear();
    }
    fm = seqan3::fm_index(ref_vec);
    {
        std::ofstream os(ref_file.substr(0, ref_file.find('.')) + ".fmi",
                         std::ios::binary);
        cereal::BinaryOutputArchive archive(os);
        archive(fm);
    }
    auto cursor = fm.cursor();
    size_t size = 0;

    for (size_t i = 0; i < seq_vec.size(); ++i) {
        if (cursor.extend_right(seqan3::assign_char_to(
                seqan3::to_char(seq_vec[i]), seqan3::dna5{}))) {
            ++size;
        } else {
            compressed.emplace_back(cursor.locate().front().second, size);
            cursor = fm.cursor();
            cursor.extend_right(seqan3::assign_char_to(
                seqan3::to_char(seq_vec[i]), seqan3::dna5{}));
            size = 1;
        }
    }

    compressed.emplace_back(cursor.locate().front().second, size);
    {
        std::ofstream os(seq_file.substr(0, seq_file.find('.')) + ".rlz",
                         std::ios::binary);
        cereal::BinaryOutputArchive archive(os);
        archive(compressed);
    }
}

void RLZ::decompress() {
    {
        std::ifstream is(seq_file.substr(0, seq_file.find('.')) + ".rlz",
                         std::ios::binary);
        cereal::BinaryInputArchive archive(is);
        archive(compressed);
    }
    {
        std::ifstream is(ref_file.substr(0, ref_file.find('.')) + ".fmi",
                         std::ios::binary);
        cereal::BinaryInputArchive archive(is);
        archive(fm);
    }
    std::ofstream decomp_file(seq_file.substr(0, seq_file.find('.')) +
                              "_decompressed.fa");
    if (!decomp_file) {
        throw std::runtime_error("Failed to open decompressed.fa for writing");
    }

    for (const auto& p : compressed) {
        for (size_t i = 0; i < p.second; ++i) {
            decomp_file << seqan3::to_char(ref_vec[p.first + i]);
        }
    }
}
