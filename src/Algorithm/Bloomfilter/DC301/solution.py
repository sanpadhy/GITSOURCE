# Implement a data structure which carries out the following operations without resizing the underlying array:

#    add(value): Add a value to the set of values.
#    check(value): Check whether a value is in the set.

# The check method may return occasional false positives (in other words, incorrectly identifying an element as part of the set), but should always correctly identify a true element.

# from hashlib import md5, sha256
# from binascii import unhexlify


class BloomFilter:
    def __init__(self):
        self.vector = 0

    def get_hash(self, value):
        return int.from_bytes(
            unhexlify(md5(value.encode("UTF-8")).hexdigest()),
            byteorder='little')

    def add(self, value):
        hashed = self.get_hash(value)
        self.vector |= hashed

    def check(self, value):
        hashed = self.get_hash(value)
        for a, b in zip(bin(hashed)[2:], bin(self.vector)[2:]):
            if bool(int(a)) and not bool(int(b)):
                return False
        return True


# Tests
bf = BloomFilter()
bf.add("test1")
bf.add("test2")
assert bf.check("test1")
assert not bf.check("test3")
