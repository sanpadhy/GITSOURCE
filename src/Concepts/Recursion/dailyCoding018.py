from collections import deque


def get_sliding_max(a, k):

    window_max_elements = list()

    if not a:
        return None
    if len(a) <= k:
        return max(a)

    dq = deque()

    for i in range(k):
        while dq and a[dq[-1]] < a[i]:
            dq.pop()
        dq.append(i)
    window_max_elements.append(a[dq[0]])

    for i in range(k, len(a)):
        while dq and dq[0] <= i - k:
            dq.popleft()

        while dq and a[dq[-1]] < a[i]:
            dq.pop()
        dq.append(i)

        window_max_elements.append(a[dq[0]])

    return window_max_elements

