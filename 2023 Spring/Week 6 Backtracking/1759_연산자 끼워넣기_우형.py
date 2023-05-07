import sys

L, C = map(int, sys.stdin.readline().split(' '))
sentence = sys.stdin.readline().rstrip().split(' ')
sentence.sort()
answer = list()
# 자음 모음
conso = 0
vowel = 0
vowels = ['a', 'e', 'i', 'o', 'u']


def backtracking(cur_index, vowel, conso):
    if len(answer) == L and vowel >= 1 and conso >= 2:
        print(''.join(answer))
        return

    for i in range(len(sentence)):
        if sentence[i] not in answer and i > cur_index:
            if sentence[i] in vowels:
                answer.append(sentence[i])
                backtracking(i, vowel + 1, conso)
                answer.pop()
            else:
                answer.append(sentence[i])
                backtracking(i, vowel, conso + 1)
                answer.pop()


backtracking(-1, 0, 0)
