/**
 * @file length_filter.h
 * @author Chase Geigle
 */

#ifndef _META_LENGTH_FILTER_H_
#define _META_LENGTH_FILTER_H_

#include "analyzers/token_stream.h"
#include "util/optional.h"

namespace meta
{
namespace analyzers
{

/**
 * Filter that only retains tokens that are within a certain length range,
 * inclusive.
 */
class length_filter : public token_stream
{
  public:
    /**
     * Constructs a length filter, reading tokens from the given source
     * and eliminating any that are shorter than min characters in length
     * or longer than max characters in length.
     */
    length_filter(token_stream& source, uint64_t min, uint64_t max);

    /**
     * Obtains the next token in the sequence.
     */
    std::string next() override;

    /**
     * Determines whether there are more tokens available in the stream.
     */
    operator bool() const override;

  private:
    void next_token();

    /**
     * The source to read tokens from.
     */
    token_stream& source_;

    /**
     * The next buffered token.
     */
    util::optional<std::string> token_;

    /**
     * The minimum length of a token that can be emitted by this filter.
     */
    uint64_t min_length_;

    /**
     * The maximum length of a token that can be emitted by this filter.
     */
    uint64_t max_length_;
};
}
}
#endif
