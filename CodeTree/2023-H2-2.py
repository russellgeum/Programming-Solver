import sys

dxs = [0, 1, 1, 1, 0, -1, -1, -1]
dys = [1, 1, 0, -1, -1, -1, 0, 1]
sdxs = [-1, 0, 1, 0]
sdys = [0, 1, 0, -1]


def checkRange(x, y):
    return 0 < x < N + 1 and 0 < y < N + 1


def checkDistance(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2)


# 산타 넘버와 산타가 이동하려는 위치를 넣음
def checkCrush(p_num, x1, y1):
    # 현재 산타 리스트를 순회하여, 인덱스가 p_num과 같다면 continue
    # 위치가 같다면 False, 1를 리턴
    # 위치 같은 것이 없으면 빈 공간이므로 True, 0을 리턴
    for i in santa:
        if i == p_num:
            continue
        if santa[i] == [x1, y1]:
            return False, i
    return True, 0


# 현재 소의 위치를 입력하여 산타를 선택하기
def selectSanta(cow):
    # 소의 위치 추출
    r1, c1 = cow
    close_distance   = 2500
    select_santa_num = 0
    select_santa_loc = [0, 0]

    # 산타를 순회
    for i in santa:
        r2, c2   = santa[i]
        distance = checkDistance(r1, c1, r2, c2)

        # 측정한 거리가 현재 최소거리보다 짧으면 선택한 산타 위치를 i, r2, c2로 업데이트
        if distance < close_distance:
            select_santa_num = i
            select_santa_loc = [r2, c2]
            close_distance = distance
        # 측정한 거리가 현재 최소거리와 같다면 r, c로 비교하여 선택
        elif distance == close_distance:
            if r2 > select_santa_loc[0]:
                select_santa_num = i
                select_santa_loc = [r2, c2]
                close_distance = distance
            elif r2 == select_santa_loc[0]:
                if c2 > select_santa_loc[1]:
                    select_santa_num = i
                    select_santa_loc = [r2, c2]
                    close_distance = distance
    return select_santa_num, select_santa_loc


# 상호작용
def interaction(crush_new_santa_num, dict_x, dict_y):
    x, y = santa[crush_new_santa_num]
    new_x = x + dict_x
    new_y = y + dict_y

    # 보드 박으로 나가면
    if not checkRange(new_x, new_y):
        del santa[crush_new_santa_num]
        faint[crush_new_santa_num] = 0
    # 보드 밖으로 나가지 않으면
    else:
        # 새 위치에 산타가 있는지 없는지 확인
        TF, p_num = checkCrush(crush_new_santa_num, new_x, new_y)
        # 있는 경우 상호작용 -> 계속 밀리고 밀림
        if not TF:
            interaction(p_num, dict_x, dict_y)
        # 있건 없건 충돌한 산타 위치는 업데이트
        santa[crush_new_santa_num] = [new_x, new_y]


# 소가 움직여서 충돌
def cow_crash(cow_loc, x1, y1, p_num, x2, y2, k):
    # 산타의 점수에 C를 더하고
    santa_score[p_num] += C
    dict_x = x1 - cow_loc[0]
    dict_y = y1 - cow_loc[1]

    # 거리 차이의 C배만큼 뒤로 밀려남
    x2 += dict_x * C
    y2 += dict_y * C
    # 보드 밖으로 나가면 santa에서 삭제
    if not checkRange(x2, y2):
        del santa[p_num]
        faint[p_num] = 0
    else:
        # 보드 안이면 기절하고 두 턴뒤에 풀림
        faint[p_num] = 2
        # 이동하려는 위치에 다른 산타와 충돌 여부 체크
        TF, crush_new_santa_num = checkCrush(p_num, x2, y2)
        # TF = True -> 즉 누가 있으면 다시 interaction
        if not TF:
            interaction(crush_new_santa_num, dict_x, dict_y)

        # 상호작용이랑 상관없이 이동
        santa[p_num] = [x2, y2]


# 산타가 움직여서 충돌
def santa_crush(p_num, x1, y1, k):
    # 산타가 움직여서 충돌하면 산타 스코어에 + D
    santa_score[p_num] += D
    dict_x = santa[p_num][0] - x1
    dict_y = santa[p_num][1] - y1

    # 거리 차이의 D배만큼 산타가 뒤로 물러남
    x1 += dict_x * D
    y1 += dict_y * D
    # 보드 밖으로 나가면 santa에서 삭제
    if not checkRange(x1, y1):
        del santa[p_num]
        faint[p_num] = 0
    else:
        # 보드 안이면 2턴 뒤에 풀림
        faint[p_num] = 1
        # 이동하려는 위치에 다른 산타와 충돌 여부 체크
        TF, crush_new_santa_num = checkCrush(p_num, x1, y1)
        # TF = True -> 즉 누가 있으면 다기 interaction
        if not TF:
            # 상호작용
            interaction(crush_new_santa_num, dict_x, dict_y)

        # 상호작용이랑 상관없이 이동
        santa[p_num] = [x1, y1]


def cow_move_rule(x1, y1, x2, y2):
    if x1 > x2:
        x1 -= 1
    elif x1 < x2:
        x1 += 1
    else:
        x1 = x1

    if y1 > y2:
        y1 -= 1
    elif y1 < y2:
        y1 += 1
    else:
        y1 = y1
    return x1, y1


def cow_move(cow_loc, k):
    # 루돌프가 이동하는 경우
    x1, y1 = cow_loc
    # 현재 루돌프 위치에서 가장 가까운 산타를 선택
    p_num, [x2, y2] = selectSanta(cow_loc)
    # 규칙에 따라서 소가 이동 -> 산타와 가장 가까워지는 방향으로 이동
    x1, y1 = cow_move_rule(x1, y1, x2, y2)

    # 이동하려는 위치가 산타와 충돌이라면, 충돌 효과 발생
    if [x1, y1] == [x2, y2]:
        cow_crash(cow_loc, x1, y1, p_num, x2, y2, k)
    return [x1, y1]


def santa_move_rule(p_num, x1, y1, x2, y2):
    # 루돌프 위치와 선택한 산타의 위치를 계산
    distance = checkDistance(x1, y1, x2, y2)

    # 산타 위치를 현재 위치로 업데이트
    new_x, new_y = x1, y1
    # 현재 산타 위치에서 4방향 탐색
    for dx, dy in zip(sdxs, sdys):
        nx = x1 + dx
        ny = y1 + dy
        # 범위를 벗어나지 않는다면, 이동한 위치와 루돌프 위치 간 새로운 거리 계산
        if checkRange(nx, ny):
            new_distance = checkDistance(nx, ny, x2, y2)
            # 새로 계산한 거리가 기존 거리보다 짧으면
            if new_distance < distance:
                # 현재 산타 넘버와 이동한 산타 위치를 넣어서
                # 이동하려는 위치에 산타가 있어서 충돌하면, False, 0을 리턴
                # 이동하려는 위치에 산타가 없어서 충돌안하면, True ,1을 리턴
                TF, _ = checkCrush(p_num, nx, ny)
                # True일 경우 이동이 가능하고, 거리 및 위치를 업데이트
                if TF:
                    distance = new_distance
                    new_x, new_y = nx, ny
    return new_x, new_y


def santa_move(cow_loc, k):
    x2, y2 = cow_loc
    # 2.1 모든 산타가 이동해야하므로 순회
    for i in range(1, P + 1):
        if santa.get(i) == None:
            continue
        if faint[i] != 0:
            faint[i] -= 1
            continue

        # 2.2 산타 위치를 선택
        x1, y1 = santa[i]
        # 2.3 루돌프 위치를 고려하여 산타가 규칙에 따라서 이동
        # 이때 다른 산타와 충돌하는지 체크해야함
        x1, y1 = santa_move_rule(i, x1, y1, x2, y2)

        # 2.4 산타가 움직였는데 루돌프랑 부딪힐 경우
        if [x1, y1] == [x2, y2]:
            # 루돌프와 산타가 층돌하여 밀려나는 경우를 계산
            santa_crush(i, x1, y1, k)
        else:
            # 충돌하지 않으면 산타 위치 업데이트
            santa[i] = [x1, y1]


if __name__ == "__main__":
    # 문제를 쪼개는 방식
    # N: 게임 격자, M: 게임 턴수, P: 산타 갯수, C: 루돌프 힘, D: 산타의 힘
    N, M, P, C, D = map(int, input().split())
    # 소의 위치
    cow_loc       = list(map(int, input().split()))

    # 산타 넘버, 산타 위치를 santa 딕셔너리에 저장
    santa = {}
    for _ in range(P):
        santa_number, x, y  = map(int, input().split())
        santa[santa_number] = [x, y]

    # 보드 초기화
    board       = [[0] * (N + 1) for _ in range(N + 1)]
    # 기절 상태 기록
    faint       = [0] * (P + 1)
    santa_score = [0] * (P + 1)

    total_score = 0
    # 게임 플레이수 M을 따라 순회
    for k in range(1, M + 1):
        # 1. 루돌프 움직임
        cow_loc = cow_move(cow_loc, k)
        # 더 이상 산타가 비어있다면 멈추기
        if len(santa) == 0:
            break

        # 2. 1번 산타부터 P번 산타까지 산타들 움직임
        santa_move(cow_loc, k)

        # 더 이상 산타가 비어있다면 멈추기
        if len(santa) == 0:
            break

        # 3. 한 턴이 끝나면 각 산타마가 스코어 +1
        for santa_number in santa:
            santa_score[santa_number] += 1

    print(*santa_score[1:])