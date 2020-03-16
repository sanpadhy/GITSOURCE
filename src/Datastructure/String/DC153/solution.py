
# Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a string.

# For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return 1 because there's only one word "cat" in between the two words.


def findDistanceBetweenWords(sentence, word1, word2): 
    start = 0
    end = 0
    distance = 0
    largest = 0

    for index, word in enumerate(sentence.split()): 
        if word == word1 or word == word2: 
            if not start: 
                lastword = word
                start = index
            else: 
                if word == lastword: 
                    start = index
                else: 
                    distance = index - start - 1 
                    if distance > largest: 
                        largest = distance

    return largest



setOfWord = "dog cat hello cat dog dog hello cat world"
print(findDistanceBetweenWords(setOfWord, "hello", "world"))




