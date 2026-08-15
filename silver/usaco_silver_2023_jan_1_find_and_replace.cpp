'''
for each test case:
    read input string S
    read target string T

    create map[52] = undefined

    # Find where each character must go
    for each position i:
        if map[S[i]] is undefined:
            map[S[i]] = T[i]
        else if map[S[i]] != T[i]:
            output -1
            continue

    answer = 0

    # Every non-changing character needs no operation
    create graph using edges:
        c -> map[c] if c != map[c]

    answer += number of edges

    # Count cycles
    visited all = false
    for every character c:
        if c has an outgoing edge and not visited:
            follow edges from c
            if you return to a visited node in the current path:
                answer += 1   # need one extra keystroke for a cycle

    # Check impossible cycle case
    if all 52 letters are used as sources
       and there exists a cycle:
        output -1
    else:
        output answer
'''
