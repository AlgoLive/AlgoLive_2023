# 0-버거 -> 패티만
# L-버거 = 햄버거번 + (L-1)-버거 + 패티 + (L-1) 버거 + 햄버거번


def make_burger(l: int) -> str:
    if l == 0:
        return "P"
    else:
        temp = make_burger(l - 1)
        ans_str = "B" + temp + "P" + temp + "B"
        return ans_str


def count_patty(burger: str, x: int) -> int:
    cnt_of_p = 0
    for i in range(x):
        if burger[i] == "P":
            cnt_of_p += 1

    return cnt_of_p


def solve(n, x) -> int:
    burger_layer, temp = 1, 1
    layer_dict = dict()

    for i in range(1, n+1):
        burger_layer = 2 * temp + 3
        temp = burger_layer
        layer_dict[i] = burger_layer

    if x <= burger_layer//2:
        ans = layer_dict[n-1] +
    else:
        ans = layer_dict[n-1] + 2


if __name__=="__main__":
    N, X = map(int, input().split())

# 1*2 + 3 -> 5*2 + 3 -> 13*2 + 3 -> 29*2 + 3
# 