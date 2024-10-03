#include <iostream>
#include <vector>

// 백준 1010번
// 문제 링크: https://www.acmicpc.net/problem/1010

// N -> M 다리를 잇는 갯수를 세우기 (조합)

int combination(int n, int r) {
    // nC0 = nCn = 1
    if (r == 0 || r == n) {
        return 1;
    }

    // nCr = nC(n-r)
    if (r > n-r) {
        r = n - r;
    }

    // 조합 계산을 위한 동적 프로그래밍 접근
    // 크기가 r+1인 벡터를 0으로 초기화 
    std::vector<int> dp(r+1, 0);
    dp[0] = 1;

    // i를 1부터 n까지 반복
    for (int i = 1; i <= n; ++i) {
        // j를 i와 r 중 작은 값부터 1까지 반복
        for (int j = std::min(i, r); j > 0; --j) {
            dp[j] = dp[j] + dp[j-1];
        }
    }

    return dp[r];
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;
        
        std::cout << combination(M, N) << std::endl;
    }

    return 0;
}