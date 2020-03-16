# You are given a set of synonyms, such as (big, large) and (eat, consume). Using this set, determine if two sentences with the same number of words are equivalent.

# For example, the following two sentences are equivalent:

#    "He wants to eat food."
#    "He wants to consume food."

# Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c): consider the case of (coach, bus) and (coach, teacher).

# Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?

def get_synonyms(pairs):
    synonyms = dict()
    for pair in pairs:
        default = min(pair)
        synonyms[pair[0]] = default
        synonyms[pair[1]] = default

    return synonyms


def are_equal(s1, s2, synonyms):
    words_1, words_2 = s1.split(), s2.split()
    if len(words_1) != len(words_2):
        return False

    def lookup(word):
        return synonyms[word] if word in synonyms else word

    for (w1, w2) in zip(words_1, words_2):
        a1 = lookup(w1)
        a2 = lookup(w2)
        if a1 != a2:
            return False

    return True


# Tests
synonyms = get_synonyms([("big", "large"), ("eat", "consume")])
assert are_equal("He wants to eat food.",
                 "He wants to consume food.",
                 synonyms)
assert not are_equal("He wants to large food.",
                     "He wants to consume food.",
                     synonyms)
