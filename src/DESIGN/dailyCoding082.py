class FileProxy:
    def __init__(self, contents):
        self.contents = contents
        self.offset = 0
        self.buffer = ""

    def read_7(self):
        start = self.offset
        end = min(self.offset + 7, len(self.contents))
        self.offset = end
        return self.contents[start:end].strip()

    def read_n(self, n):
        while len(self.buffer) < n:
            additional_chars = self.read_7()
            if not (additional_chars):
                break
            self.buffer += additional_chars

        n_chars = self.buffer[:n]
        self.buffer = self.buffer[n:]
        return n_chars.strip()


fp = FileProxy("Hello world")
fp.read_7()
fp.read_7()
fp.read_7()

fp = FileProxy("Hello world")
fp.read_n(8)
fp.read_n(8)

fp = FileProxy("Hello world")
fp.read_n(4)
fp.read_n(4)
fp.read_n(4)
