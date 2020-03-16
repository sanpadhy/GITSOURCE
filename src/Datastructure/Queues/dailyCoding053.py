class Queue:
    def __init__(self):
        self.MasterStack = list()
        self.HelperStack = list()

    def __repr__(self):
        return str(self.MasterStack)

    def enqueue(self, val):
        self.MasterStack.append(val)

    def dequeue(self):
        if not self.MasterStack:
            return None

        while self.MasterStack:
            self.HelperStack.append(self.MasterStack.pop())
        val = self.HelperStack.pop()
        while self.HelperStack:
            self.MasterStack.append(self.HelperStack.pop())
        return val


q = Queue()
q.enqueue(1)
print(q.MasterStack)
q.enqueue(2)
print(q.MasterStack)
q.enqueue(3)
print(q.MasterStack)
val = q.dequeue()
print(val)
print(q.MasterStack)
val = q.dequeue()
print(val)
print(q.MasterStack)
