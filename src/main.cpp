#include <seqan3/argument_parser/all.hpp>
#include <seqan3/core/debug_stream.hpp>
#include <seqan3/alphabet/nucleotide/dna5.hpp>
#include <seqan3/core/debug_stream.hpp>
#include <seqan3/io/sequence_file/input.hpp>
#include <seqan3/search/fm_index/fm_index.hpp>
#include <string>
#include <vector>
#include <seqan3/alphabet/container/bitpacked_sequence.hpp>
#include <fstream>
#include "rlz.h"

int main(int argc, char const** argv) {
    seqan3::argument_parser parser("RLZ-Parser", argc, argv);
    std::string ref_file;
    std::string seq_file;
    bool decompress;

    parser.add_positional_option(ref_file, "Reference file to compress.");
    parser.add_positional_option(seq_file, "Sequence file to compress.");
    parser.add_flag(decompress, 'd', "decompress", "Decompress the sequence file.");
    parser.info.version = "1.0.0";
    parser.info.author = "Dhruv R Makwana";
    parser.info.short_description = "RLZ compression tool.";
    parser.info.description = std::vector<std::string>{
        "RLZ is a compression tool that compresses a sequence file using a "
        "reference file. The reference file is used to build a FM Index. The "
        "sequence file is then compressed using the FM Index. The compressed "
        "file is then written to disk."};
    
    try {
        parser.parse();
    } catch (seqan3::argument_parser_error const & ext) {
        seqan3::debug_stream << "[PARSER ERROR] " << ext.what() << "\n";
        return -1;
    }

    RLZ rlz(ref_file, seq_file);
    if(decompress){
        rlz.decompress();
    } else {
        rlz.compress();
    }
    return 0;
}