import sys
from collections import deque
input = sys.stdin.readline


# 1. 기사 이동 가능 여부 함수 정의
def check(x1, y1, x2, y2):
    # 1-1. 그래프를 벗어나는 경우(벽인 경우) False 반환
    if x1 < 1 or y1 < 1 or x2 > N - 1 or y2 > M - 1:
        return False
    # 1-2.
    for x in range(x1, x2 + 1):
        for y in range(y1, y2 + 1):
            # 해당 위치가 벽일 경우 False 반환
            if knight_graph[x][y] == 2: return False
    # 1-3. True 반환
    return True


# 1. 이동 함수 정의
def move(target, knight_info, knight_graph, dir):
    """
    target: 옮겨야할 기사
    info: 기사의 딕셔너리 정보 [x, y, h, w, k]
    knight_graph: 기사의 현재 위치 그래프
    dir: 왕이 명령한 방향
    """
    # 1-1. 업데이트용 딕셔너리, 조정이 필요한 기사 리스트, 밀려난 기사 번호 리스트 생성
    updated_info   = knight_info.copy()
    need_to_moving = deque([target])
    array = []

    # 1-2 조정이 필요한 기사가 없어질때까지 반복
    while need_to_moving:
        # 1-2-1. 조정이 필요한 기사 꺼내기
        knight        = need_to_moving.popleft()
        x, y, h, w, k = knight_info[knight]

        # 1-2-2. 기사가 소속한 영역을 모두 이동
        x1 = x + dirs[dir][0]
        y1 = y + dirs[dir][1]
        x2 = x + h - 1 + dirs[dir][0]
        y2 = y + w - 1 + dirs[dir][1]

        # 1-2-3. 기사가 이동한 위치가 벽일 경우 (False, 기존의 기사 정보 딕셔너리, 기사 위치 그래프, None 반환)
        if not check(x1, y1, x2, y2):
            return [False, knight_info, knight_graph, None]

        # 1-2-4. 기사 정보 업데이트
        # if not check에 걸리지 않았다면 이동 가능한 영역이므로 이동한 영역을 update_info에 추가
        updated_info[knight] = [x1, y1, h, w, k]

        # 1-2-5. 이동하였으므로 이제 이동 위치에 다른 기사가 있는지 확인
        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                # 이동 위치 정보 != [0, 자기 자신] and 이동 위치가 현재 이동 대기 중인 기사 목록에도 없다면
                # 새로운 위치에 다른 기사가 있는 것이므로, need_to_moving에 append
                # 밀려난 기사는 array에 append
                if knight_graph[i][j] not in [0, knight] and knight_graph[i][j] not in need_to_moving:
                    need_to_moving.append(knight_graph[i][j])
                    array.append(knight_graph[i][j])

    # 1-3. 기사 위치 그래프 업데이트
    knight_graph = [[0 for _ in range(M)] for _ in range(N)]
    for knight in updated_info.keys():
        x, y, h, w, k = updated_info[knight]
        x1 = x
        y1 = y
        x2 = x + h - 1
        y2 = y + w - 1
        for i in range(x1, x2 + 1):
            for j in range(y1, y2 + 1):
                knight_graph[i][j] = knight

    # 1-4. (True, 업데이트된 기사 정보 딕셔너리, 밀려난 기사 번호 리스트 반환)
    return [True, updated_info, knight_graph, array]


# 3. 데미지 함수 정의
def damage(knight_info, knight_graph, array):
    # 3-1. 밀려난 기사들의 위치를 순회
    for key in array:
        r, c, h, w, k = knight_info[key]
        cnt = 0

        # 3-1-1. 함정 갯수 체크
        for i in range(r, r + h):
            for j in range(c, c + w):
                if knight_graph[i][j] == 1:
                    cnt += 1

        # 3-1-2. 함정 갯수가 현재 체력보다 같거나 많을 경우,
        # 해당 칸을 비우고 딕셔너리 정보 삭제
        if cnt >= k:
            for i in range(r, r + h):
                for j in range(c, c + w):
                    knight_graph[i][j] = 0
            del knight_info[key]

        # 3-1-3. 이외의 경우 체력 감소
        else:
            knight_info[key][-1] -= cnt

    # 3-2. 정보 반환
    return knight_info, knight_graph


if __name__ == "__main__":
    # 방향
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    # L, N, Q = 4, 3, 3
    # chess_graph = [
    #     [0, 0, 0, 1, 0],
    #     [0, 0, 0, 1, 0],
    #     [0, 1, 1, 0, 1],
    #     [0, 0, 0, 2, 0]]
    # knight_info = {
    #     1: [1, 2, 2, 1, 5],
    #     2: [2, 1, 2, 1, 1],
    #     3: [3, 2, 1, 2, 3]}
    # knight_order = [
    #     [1, 2],
    #     [2, 1],
    #     [3, 3]]

    L, N, Q = map(int, input().split())
    # 체스보드 그래프 생성
    chess_graph = [[0]] + [[0] + list(map(int, input().split())) for _ in range(L)]
    # 기사 정보 딕셔너리 생성
    knight_info = dict()
    for i in range(1, N + 1):
        knight_info[i] = list(map(int, input().split()))
    # 기사 정보 딕셔너리 원본을 카피한 표준 정보 -> 나중에 각 기사들이 피해입은 데미지를 계산하기 위한 기준
    standard_info = knight_info.copy()

    # 체스보드의 세로 길이, 가로 길이
    N, M = len(chess_graph), len(chess_graph[-1])

    # 기사 위치 그래프 생성 (0으로 초기화)
    knight_graph = [[0 for _ in range(len(chess_graph[-1]))] for _ in range(len(chess_graph))]
    for key in knight_info.keys():
        r, c, h, w, k = knight_info[key]
        # 각 위치에 해당하는 기사의 키를 붙여주기
        for i in range(r, r + h):
            for j in range(c, c + w):
                knight_graph[i][j] = key




    # 왕의 명령 횟수 만큼 반복
    for _ in range(Q):
        # 옮겨야 할 기사와 방향
        target, dir = map(int, input().split())
        # target, dir = knight_order.pop(0)
        try:
            if knight_info[target]:
                # 1. 기사 이동
                change, knight_info, knight_graph, array = move(target, knight_info, knight_graph, dir)
                # 2. 다른 기사를 만나면 데미지를 입히므로 손상 데미지 계산
                if change:
                    knight_info, knight_graph = damage(knight_info, knight_graph, array)
        except:
            pass

    # 결과 출력
    ans = 0
    for knight in knight_info.keys():
        ans += standard_info[knight][-1] - knight_info[knight][-1]
    print(ans)