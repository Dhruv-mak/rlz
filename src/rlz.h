#ifndef RLZ_H
#define RLZ_H

#include <seqan3/alphabet/nucleotide/dna5.hpp>
#include <seqan3/core/debug_stream.hpp>
#include <seqan3/io/sequence_file/input.hpp>
#include <seqan3/search/fm_index/fm_index.hpp>
#include <seqan3/alphabet/container/bitpacked_sequence.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/vector.hpp>
#include <string>
#include <vector>
#include <fstream>

class RLZ {
public:
    std::string ref_file;
    std::string seq_file;
    seqan3::fm_index<seqan3::dna5, seqan3::text_layout::single> fm;
    seqan3::bitpacked_sequence<seqan3::dna5> seq_vec;
    seqan3::bitpacked_sequence<seqan3::dna5> ref_vec;
    std::vector<std::pair<uint16_t, uint16_t>> compressed;

    RLZ(std::string ref_file, std::string seq_file);
    void compress();
    void decompress();
    
private:
    void load_file_to_vector(const std::string& file_path, seqan3::bitpacked_sequence<seqan3::dna5>& vec);
};

#endif  // RLZ_H
