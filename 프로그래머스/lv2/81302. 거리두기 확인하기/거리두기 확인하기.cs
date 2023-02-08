using System;
using System.Linq;

public class Solution {
    bool OOB(int y, int x)
        {
            return x < 0 || x > 4 || y < 0 || y > 4;
        }

        private string[] GetRow(string[,] places, int row)
        {
            return Enumerable.Range(0, places.GetLength(1)).Select(x => places[row, x]).ToArray();
        }

        private int check(string[] place)
        {
            int[] dirY = {-1, 0, 1, 0};
            int[] dirX = {0, -1, 0, 1};

            int[] dirY2 = {-1, 1, 1, -1};
            int[] dirX2 = {-1, -1, 1, 1};

            for (int y = 0; y < place.Length; y++)
            {
                for (int x = 0; x < place[y].Length; x++)
                {
                    if (place[y][x] != 'P')
                        continue;

                    int nowY = y;
                    int nowX = x;

                    //상하좌우 *1 체크
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nextY = nowY + dirY[dir];
                        int nextX = nowX + dirX[dir];


                        if (OOB(nextY, nextX))
                            continue;

                        if (place[nextY][nextX] == 'P')
                            return 0;
                    }

                    //상하좌우 *2 체크
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nextY = nowY + 2 * dirY[dir];
                        int nextX = nowX + 2 * dirX[dir];


                        if (OOB(nextY, nextX))
                            continue;

                        if (place[nextY][nextX] == 'P')
                        {
                            if (place[y + dirY[dir]][x + dirX[dir]] != 'X')
                                return 0;
                        }
                    }

                    //대각선 체크
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nextY = nowY + dirY2[dir];
                        int nextX = nowX + dirX2[dir];

                        if (OOB(nextY, nextX))
                            continue;

                        if (place[nextY][nextX] == 'P')
                        {
                            if (place[y][nextX] != 'X' || place[nextY][x] != 'X')
                                return 0;
                        }
                    }
                }
            }

            return 1;
        }


        public int[] solution(string[,] places)
        {
            int[] answer = new int[5];

            for (int i = 0; i < 5; i++)
            {
                string[] place = GetRow(places, i);
                answer[i] = check(place);
            }

            return answer;
        }
}