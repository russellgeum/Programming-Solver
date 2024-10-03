"""
M명의 사람이 있는데, 1번 사람은 1분에, 2번 사람은 2분에 ... ... 베이스캠프에서 편의점으로 이동
1. 이 모든 일은 n x n 격자에서 진행
2. 사람들이 목표로 하는 편의점은 다름

격자에 있는 모든 사람들 모두가 본인이 가고 싶은 편의점으로 1칸 이동
최단 거리로 움직이며, 상, 좌, 우 하 우선 순위로 이동
최단 거리: 거쳐야하는 칸의 수가 최소

편의점에 도착하면 편의점에서 멈추고, 다른 사람들은 편의점이 있는 칸을 지나가지 못함

현재 시간이 t분이고 t<=m을 만족하면, 1번 사람은 자신이 가장 가고 싶은 편의점과
가장 가까운 베이스 캠프에 들어감. 가장 가까이에 있다는 뜻은 편의점과 가장 최댄 거리의 편의점
- 가장 가까운 베이스캠프가 여러개이면 행이 작은 베이스캠프
- 행이 같다면 열이 작은 베이스캠프로 이동
- 베이스캠프에 사람이 들어가면 다른 사람은 지나갈 수 없음
"""
import sys
from collections import deque
INT_MAX = sys.maxsize

def check_range(x, y):
    # 좌표가 격자 내에 있는지 체크
    return 0 <= x < n and 0 <= y < n


def check_moving(x, y):
    # 범위를 벗어나지 않으면, 방문한 적이 없고, 이동 가능한 곳인지 체크
    return check_range(x, y) and not visited[x][y] and board[x][y] != 2


def check_end():
    for i in range(1, m+1):
        if people_location[i] != store_info[i]:
            return False
    return True


def BFS(location):
    # 주어진 편의점 위치를 기준으로, 가장 가까운 스토어를 찾는다.
    # 입력값은 (x, y) 튜플
    # visited, step 값을 모두 초기화
    for i in range(n):
        for j in range(n):
            visited[i][j] = False
            minimum[i][j] = 0

    q = deque()
    q.append(location)
    sx, sy = location
    visited[sx][sy] = True
    minimum[sx][sy] = 0

    # BFS를 진행
    while q:
        x, y = q.popleft()

        # 각 위치에서 상, 좌, 우, 하 순서로 인접한 칸을 큐에 넣음
        for dx, dy in zip(dxs, dys):
            nx = x + dx
            ny = y + dy

            if check_moving(nx, ny):
                # 방문 체크
                visited[nx][ny] = True
                # 누적 스텝 + 1
                minimum[nx][ny] = minimum[x][y] + 1
                q.append((nx, ny))


def allocation_store():
    # 2. 모든 사람이 한 번에 움직인다.
    for i in range(1, m+1):
        # 2.1 아직 격자 밖에 있거나, 이미 편의점에 도착한 사람은 제외한다.
        if people_location[i] == (-1, -1) or people_location[i] == store_info[i]:
            continue

        # 2.2 원해는 현재 위치에서 최단거리를 구해야 한다.
        # 다만 편의점 위치를 시작으로 현재 위치까지 오는 최단거리 계산이 편하다.
        BFS(store_info[i])

        # 현재 i번째 사람 위치를 획득
        px, py = people_location[i]

        # 현재 위치에서 상좌우하 중 가장 최단거리 값이 작은 곳을 고르면 됨
        min_dist = INT_MAX
        min_x, min_y = -1, -1
        for dx, dy in zip(dxs, dys):
            nx = px + dx
            ny = py + dy
            # 이동 위치가 범위 안이고, 방문하였고, minimum[nx][ny]보다 작으면 위치 업데이트
            if check_range(nx, ny) and visited[nx][ny] and min_dist > minimum[nx][ny]:
                min_dist = minimum[nx][ny]
                min_x, min_y = nx, ny
        people_location[i] = (min_x, min_y)

    # 편의점에 도착한 사람은 위치를 2로 바꾼다.
    for i in range(1, m+1):
        if people_location[i] == store_info[i]:
            px, py = people_location[i]
            board[px][py] = 2


    # curr_t가 m보다 크다면 패스합니다.
    if time > m:
        return


    # 3. 최단 거리를 찾으므로 BFS를 활용
    # 3.1 편의점에서 가장 가까운 베이스캠프를 찾기 위해 BFS를 활용
    BFS(store_info[time])

    # 3.2 편의점에서 가장 가까운 베이스캠프를 선택 -> (i, j)가 증가하는 순으로 돌리기 때문에
    # 가장 가까운 베이스캠프가 여러 개여도 행 열 우선 순위대로 골라감
    min_dist = INT_MAX
    min_x, min_y = -1, -1
    for i in range(n):
        for j in range(n):
            # 방문 가능한 베이스캠프 중, 거리가 가장 가까운 위치 찾기
            if visited[i][j] and board[i][j] == 1 and min_dist > minimum[i][j]:
                min_dist = minimum[i][j]
                min_x, min_y = i, j
    # 3.3 우선 순위가 가장 높은 베이스캠프로 위치 이동
    people_location[time] = (min_x, min_y)
    # 3.4 해당 베이스캠프는 앞으로 이동 불가능 칸임을 표시
    board[min_x][min_y] = 2



if __name__ == "__main__":
    # dx, dy값을 문제에서의 우선순위인 상좌우하 순으로 적어줍니다.
    dxs   = [-1,  0, 0, 1]
    dys   = [ 0, -1, 1, 0]
    # n, m  = map(int, input().split())
    # board = [list(map(int, input().split())) for _ in range(n)]
    #
    # # {사람 번호: 원하는 스토어 위치} 딕셔너리
    # store_info = {}
    # for idx in range(1, m+1):
    #     store_info[idx] = tuple(map(int, input().split()))

    n, m = 5, 3
    board = [
        [0, 0, 0, 0, 0],
        [1, 0, 0, 0, 1],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0],
        [0, 0, 0, 0, 1],
    ]
    store_info = {
        1: (2-1, 3-1),
        2: (4-1, 4-1),
        3: (5-1, 1-1)
    }

    # 사람의 현재 위치를 저장할 딕셔너리 초기화
    people_location = {}
    for idx in range(1, m+1):
        people_location[idx] = (-1, -1)

    # BFS에 사용할 방문 여부 표시
    visited = [[False] * n for _ in range(n)]
    # 최단거리 결과를 기록
    minimum = [[0] * n for _ in range(n)]

    time = 0
    # 1분에 한번씩 시뮬레이션을 진행합니다.
    while True:
        time += 1
        allocation_store()
        # 전부 이동이 끝났다면 종료합니다.
        if check_end():
            break

    print(time)