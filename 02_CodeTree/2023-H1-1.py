import sys
from collections import deque

"""
포탑 부수기
N x M 격자가 있고 모든 위치에는 포탑이 존재 (포탑 갯수는 NM개)
1. 포탑: 공격력이 존재하며, 상황에 따라 공격력이 늘어나거나 줄어듬
2. 공격력이 0이하 -> 해당 포탑은 부셔지며 공격 불가능

3. 공격자 선정
- 공격력이 가장 낮은 것을 찾는다.
- 만약 공격력이 가장 낮은 포탑이 2개 이상이면, 가장 최근에 공격한 포탑
- 가장 최근에 공격한 포탑이 2개 이상이면, 행+열의 값이 가장 큰 포탑
- 행+열의 값이 가장 큰 포탑이 2개 이상이면, 열 값이 가장 큰 포탑
- 부서지지 않은 포탑 중 가장 약한 포탑 = 공격자
    공격자가 되면 가장 약하므로 N+M 공격력 증가

4. 공격자의 공격
공격자가 공격하는 타겟을 선정해야함
- 공격력이 가장 높은 것을 찾는다.
- 만약 공격력이 가장 높은 포탑이 2개 이상이면, 공격한지 가장 오래된 포탑
- 공격한지 가장 오래된 포탑이 2개 이상이면, 행과 열의 합이 가장 작은 포탑
- 만약 합이 가장 작은 포탑이 2개 이상이면, 열이 가장 작은 포탑

5. 레이저 공격
- 상하좌우 4개 방향
- 부서진 포탑이 있는 위치는 지날수 없음
- 가장자리에서 막힌 방향으로 진행하면 반대편으로 나옴
- 최단경로가 2개 이상이면 우 - 하 - 좌 - 상 우선으로 움직이는 경로 선택

6. 포탄 공격
- 공격 대상은 공격자 공격력만큼의 피해
- 주변 8개 포탑도 피해를 입는데, 공격자 공격력의 절반
- 공격자는 영향 X
- 가장자리에 떨어지면 레이저처럼 반대편에 영향

7. 포탑 부서짐
- 공격력이 0이하가 된 포탑은 부서짐

8. 포탑 정비
- 공격자도 아니고, 피해를 안 입은 포탑은 공격력 1 증가

- 턴 종료
"""


def check_break():
    # 모든 칸을 돌아서 0 미만으로 파괴된 포탑은 0으로 만듬 == 부서진 포탑
    for x in range(N):
        for y in range(M):
            if arr[x][y] < 0:
                arr[x][y] = 0


def check_max():
    # 배열에서 가장 높은 값을 선택하는 함수
    return max([max(line) for line in arr])


def check_attack():
    power = 5001
    ax = ay = 0
    for x in range(N):
        for y in range(M):
            # 공격력 0인 포탑은 무시
            if arr[x][y] == 0:
                continue

            # 공격력이 power보다 작으면, power = arr[x][y]로 업데이트
            if arr[x][y] < power:
                power = arr[x][y]
                ax, ay = x, y

            # 또 다른 포탑이 공격력과 같아서 2개 이상이면
            elif arr[x][y] == power:
                # 또 다른 포탑의 공격 시간이 더 큰 것 == 0이 시작 시간
                if attack_time[x][y] > attack_time[ax][ay]:
                    ax, ay = x, y
                # 공격 시간도 같다면, 행+열 값이 큰 것을 선택
                elif attack_time[x][y] == attack_time[ax][ay]:
                    # 행 열의 합이 더 큰 것을 선택
                    if x + y > ax + ay:
                        ax, ay = x, y
                    # 행 열의 합도 같다면
                    elif x + y == ax + ay:
                        if y > ay:
                            ay = y
    return ax, ay


def check_target(ax, ay):
    power = -1
    tx = ty = 0
    for x in range(N):
        for y in range(M):
            # 공격력이 0인 포탑은 무시
            if arr[x][y] == 0:
                continue

            # 공격자 좌표와 같으면 무시
            if x == ax and y == ay:
                continue

            # 공격력이 power(-1)보다 크다면, power를 공격력으로 업데이트 -> 가장 강한 포탑
            if arr[x][y] > power:
                power = arr[x][y]
                tx, ty = x, y
            # 현재 고른 포탑이 현재 공격력과 같으면 2개 이상
            elif arr[x][y] == power:
                # 현재 고른 포탑의 공격 시간이 더 전이면 업데이트 (가장 오래된 것 선택)
                if attack_time[x][y] < attack_time[tx][ty]:
                    tx, ty = x, y
                # 공격 시간대가 같다면
                elif attack_time[x][y] == attack_time[tx][ty]:
                    # 행과 열 합이 더 적은 포탑으로 업데이트
                    if x + y < tx + ty:
                        tx = x
                        ty = y
                    elif x + y == tx + ty:
                        if y < ty:
                            tx = x
                            ty = y
    return tx, ty


def laser(ax, ay, tx, ty):
    # 경로 체크하기 위해 q에 리스트 요소 정의
    q = deque()
    q.append((ax, ay, []))  # x, y, route
    visited = [[False] * M for _ in range(N)]
    visited[ax][ay] = True

    while q:
        # 현재 위치와 루트를 꺼내기
        x, y, route = q.popleft()
        # 주변 4방향 탐색
        for dir in range(4):
            # 가장자리를 넘어가면 건너편 자리로 감
            # 예를 들어 1 2 3 4 1이면 4에서 1 더하고 4로 나눈 몫은 1
            nx = (x + dx[dir]) % N
            ny = (y + dy[dir]) % M

            # 방문하였으면 무시
            if visited[nx][ny]:
                continue
            # 0이면 무시
            if arr[nx][ny] == 0:
                continue

            # 타겟에 도달한 경우
            if nx == tx and ny == ty:
                arr[nx][ny] -= point
                # 경로 추적
                for rx, ry in route:
                    arr[rx][ry] -= half_point
                    attack[rx][ry] = True
                return True

            # 타게에 돋라하지 않으면 방문한 후, 경로 체크
            temp_route = route[:]
            temp_route.append((nx, ny))
            visited[nx][ny] = True
            q.append((nx, ny, temp_route))
    # 타겟에 도달하지 못하는 경우
    return False


def shell(ax, ay, tx, ty):
    arr[tx][ty] -= point
    ddx = dx + [1, 1, -1, -1]
    ddy = dy + [-1, 1, -1, 1]
    # 포탄이 터지는 4방향 탐색
    for dir in range(8):
        nx = (tx + ddx[dir]) % N
        ny = (ty + ddy[dir]) % M
        # 위치가 공격자 위치와 같으면 무시
        if nx == ax and ny == ay:
            continue

        # 그 외는 절반만큼 피해
        arr[nx][ny] -= half_point
        # 공격 받는 여부는 True
        attack[nx][ny] = True


def check_turret():
    # 각 배열을돌면서 공격자 or 공격받은 자가 아닌 포탑은 공격력 +1
    turret = []
    turret_count = 0
    for x in range(N):
        for y in range(M):
            if arr[x][y] == 0:  # 죽은 포탑은 무시
                continue
            turret_count += 1
            if attack[x][y]:  # 공격한 이력이 있으면 무시
                continue
            turret.append((x, y))

    if turret_count == 1:
        print(check_max())
        exit(0)
    for x, y in turret:
        arr[x][y] += 1


if __name__ == "__main__":
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    # N, M: 격자 // K: 턴 횟수
    N, M, K = 4, 4, 1
    arr = [
        [0, 1, 4, 4],
        [8, 0, 10, 13],
        [8, 0, 11, 26],
        [0, 0, 0, 0]
    ]
    attack_time = [[0] * M for _ in range(N)]
    time = 1

    for k in range(K):
        # 매번 돌 때마다 공격 관련 여부 배열을 잡아준다.
        attack = [[False] * M for _ in range(N)]

        # 1. 공격자 선정
        attack_i, attack_j = check_attack()
        # 2. 선정한 공격자는 N + M 만큼 공격력 증가
        arr[attack_i][attack_j] += N + M
        # 공격력에 대해 포인트와 절반 포인트 계산
        point = arr[attack_i][attack_j]
        half_point = point // 2

        # 공격자로 선정하였으므로 공격자 배열에 True
        attack[attack_i][attack_j] = True
        # 공격 시간 체크하고 +1
        attack_time[attack_i][attack_j] = time
        time += 1

        # 3. 공격자의 공격
        target_i, target_j = check_target(attack_i, attack_j)
        attack[target_i][target_j] = True

        if not laser(attack_i, attack_j, target_i, target_j):
            shell(attack_i, attack_j, target_i, target_j)

        # 4. 포탑 부서짐
        check_break()

        # 5. 포탑 복구
        check_turret()

    print(check_max())