"""
메이즈 러너
미로는 N x N 크기 격자. 각 위치는 (r, c)의 형태. 좌상단 (1, 1)
미로의 칸은
    빈 칸: 참가자가 이동 가능한 칸
    벽 칸: 참가자가 이동 안되는 칸, 1 ~ 9 내구도 / 회전할때 내구도 1 깍임 / 내구도 0이면 빈칸
    출 구: 참가자가 해당 칸에 도달하면 즉시 탈출

def 모든 참가자는 동시에 움직임
    for in 참가자
        참가자
        if 벽이면 이동 불가능

        움직일수 있는 칸이 2개 이상
        if 상하 중 가까운 거리
            상하 이동 선택 (nx += -= 1)
        움직일 수 있는 칸이 1개
        if 좌우 중 가까운 거리
            좌우 이동 선택 (ny += -= 1

        if nx, ny가 0이면
            참가자 위치 업데이트
            continue

def 미로 회전
    회전하기 전에 내구도 1 미리 깍기
    1명의 참가자와 출구를 포함한 가장 작은 정사각형 잡기 -> 정사각형 잡는 함수
        if 가장 작은 정사각형이 2개 이상이면
            if r1 < r2

            if r1 == r2
                if c1 < c2
        정사각형 1개 선택
    정사각형 = rotate(정사각형)

"""
def getInput():
    # N: 미로의 크기, M: 참가자의 좌표, K: 게임 시간
    N, M, K = map(int, input().split())
    # 벽돌의 상태를 기록하는 미로
    maze_board = [[0] * (N+1) for _ in range(N+1)]
    for _ in range(1, N+1):
        maze_board.append([0] + list(map(int, input().split())))
    # 회전 구현을 위한 2차원 배열
    temp_board  = [[0] * (N+1) for _ in range(N+1)]
    # 참가자 정보
    participant = [(-1, -1)] + [tuple(map(int, input().split())) for _ in range(M)]
    # 출구 정보
    exit        = tuple(map(int, input().split()))
    return N, M, K, maze_board, temp_board, participant, exit


def move():
    global M, maze_board, participant, exit, answer
    # 모든 참가자에 대하여 이동을 진행 -> 한 번에 이동한다고 하였다.
    for number in range(1, M+1):
        # 참가자가 이미 출구에 있다면 무시한다.
        if participant[number] == exit:
            continue
        # 참가자의 현재 위치와 출구를 잡는다.
        tx, ty = participant[number]
        ex, ey = exit

        # 참가자의 위치와 출구가 다른 경우 참가자를 이동시킨다.
        # 상하 먼저 -> 좌우 먼저
        if tx != ex:
            nx, ny = tx, ty
            # 출구가 아래에 있음 -> nx를 아래로 땡김
            if ex > nx:
                nx += 1
            # 출구가 위에 있음 -> nx를 위로 밀음
            else:
                nx -= 1

            # 벽이 없다면, 위치 이동
            if maze_board[nx][ny] == 0:
                participant[number] = (nx, ny)
                answer += 1
                continue

        # 상하를 우선할 수 없다면 좌우
        if ty != ey:
            nx, ny = tx, ty
            if ey > ny:
                ny += 1
            else:
                ny -= 1

            # 벽이 없다면 위치 이동
            if maze_board[nx][ny] == 0:
                participant[number] = (nx, ny)
                answer += 1
                continue
    # 모든 참가자의 이동이 끝났으므로 이제 미로를 회전한디.
    # 이때 한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형을 찾아야 한다.


def minimm_Square():
    # 초기 sx, sy, squre_size는 0, 0, 0
    global sx, sy, squre_size, exit
    ex, ey = exit

    # 어떤 정사각형이 가장 최적의 크기인지 모른다. -> 가장 작은 것부터 큰 것으로 찾는다.
    for size in range(2, N+1):
        # 가장 좌상단 r좌표가 작은 것부터 탐색한다.
        for x1 in range(1, N - size + 1 + 1):
            # 가장 좌상단 c좌표가 작은 것부터 탐색한다.
            for y1 in range(1, N - size + 1 + 1):
                # (x1, y1) -> (x2, y2) 장사각형 우하단 좌표
                x2 = x1 + size - 1
                y2 = x1 + size - 1

                # 만약 출구가 없다면 무시
                if not (x1 <= ex <= x2 and y1 <= ey <= y2):
                    continue

                # 만든 (x1, y1) ~ (x2, y2) 사이즈의 정사각형마다
                # 만약 출구가 있다면 이제 최소 사람 1명이 있는지 판단
                # - 참가자 정보를 순회해서, 각 참가자 위치가 정사각형 안에 있는지 판단
                # - 또한 출구의 참가자는 제외
                participant_in = False
                for l in range(1, M+1):
                    tx, ty = participant[l]
                    # 참가자 위치가 정사각형 안에 있고, 출구에 있는 경우는 제외
                    if x1 <= tx <= x2 and y1 <= ty <= y2:
                        if not (tx == ex and ty == ey):
                            participant_in = True

                # 만약 한 명 이상의 참가자가 해당 정사각형 안에 있다면
                if participant_in:
                    sx, sy, squre_size = x1, y1, size
                    return


def rotate_Square():
    global sx, sy, temp_board, maze_board, squre_size, exit
    # 미리 0이 아닌 벽돌은 내구도 1 깍기
    for x in range(sx, sx+squre_size):
        for y in range(sy, sy+squre_size):
            if maze_board[x][y]:
                maze_board[x][y] -= 1

    for x in range(sx, sx+squre_size):
        for y in range(sy, sy+squre_size):
            # (sx, sy)를 (rx, ry)로 옮기는 변환
            rx = y - sy
            ry = squre_size - (x - sx) - 1

            temp_board[rx + sx][ry + sy] = maze_board[x][y]

    # temp_board의 정사각형 영역 값을 maze_board에 복사
    for x in range(sx, sx+square_size):
        for y in range(sy, sy+square_size):
            maze_board[x][y] = temp_board[x][y]

    # 참가자와 출구도 회전해야 한다.
    # m명의 참가자들을 모두 확인합니다.
    for i in range(1, M + 1):
        tx, ty = participant[i]
        # 해당 참가자가 정사각형 안에 포함되어 있을 때에만 회전시킵니다.
        if sx <= tx < sx + square_size and sy <= ty < sy + square_size:
            # (sx, sy)를 (rx, ry)로 옮기는 변환
            rx = ty - sy
            ry = square_size - (tx - sx) - 1
            participant[i] = (rx + sx, ry + sy)

    # 출구에도 회전 진행
    ex, ey = exit
    if sx <= ex < sx + squre_size and sy <= ey < sy + squre_size:
        rx = ey - sy
        ry = squre_size - (ex - sx) - 1
        exit = (rx + sx, ry + sy)


if __name__ == "__main__":
    N, M, K, maze_board, temp_board, participant, exit = getInput()
    # 답을 기록할 변수
    answer = 0
    # 회전해야하는 최소 정사각형 좌상단 위치와 사이즈
    sx, sy, square_size = 0, 0, 0

    for _ in range(K):
        # 1. 모든 참가자를 이동
        move()

        # 2. 모든 사람이 출구에 도달했는지 판단
        # 3. 모든 사람이 출구에 도달했다면 종료
        # 모든 사람이 출구로 탈출했는지 판단합니다.
        is_all_escaped = True
        for i in range(1, M + 1):
            if participant[i] != exit:
                is_all_escaped = False
        if is_all_escaped: # 만약 모든 사람이 출구로 탈출했으면 바로 종료합니다.
            break

        # 4. 1명 이상의 참가자와 출구를 포함한 가장 작은 정사각형 찾기
        minimm_Square()

        # 5. 정사각형 내부의 벽을 회전 -> 모든 참가자들 및 출구를 회전
        rotate_Square()

    print(answer)
    print(exit[0], exit[1])