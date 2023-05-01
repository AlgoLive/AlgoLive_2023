# A를 B번 곱한 수를 C로 나눈 나머지 출력
import sys
sys.setrecursionlimit(10 ** 6) # 숫자는 예시


def power(A, B, C):
    if B == 1:
        return A % C
    else:
        tmp = power(A, B//2, C)
        if B % 2 == 1:
            return (tmp * tmp * A) % C
        elif B % 2 == 0:
            return (tmp * tmp) % C


if __name__ == "__main__":
    A, B, C = map(int, input().split())
    ans = power(A, B, C)
    print(ans)