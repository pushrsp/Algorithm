import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    private static int N;
    private static char[][] board = new char[2][2];

    private static char[][] clockwise(char[][] clock) {
        return new char[][]{{clock[1][0], clock[0][0]}, {clock[1][1], clock[0][1]}};
    }

    private static char[][] otherClockwise(char[][] clock) {
        return new char[][]{{clock[0][1], clock[1][1]}, {clock[0][0], clock[1][0]}};
    }

    private static boolean isValidCharacter(char[][] temp) {
        return (temp[0][0] == 'H' && temp[0][1] == 'E' && temp[1][1] == 'P' && temp[1][0] == 'C') ||
                (temp[0][0] == 'H' && temp[1][0] == 'E' && temp[1][1] == 'P' && temp[0][1] == 'C');
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int i = 0; i < 2; i++) {
            String s = br.readLine();
            for (int j = 0; j < 2; j++) {
                board[i][j] = s.charAt(j);
            }
        }

        boolean ret = isValidCharacter(board);

        if (!ret) {
            char[][] temp = new char[][]{{board[0][0], board[0][1]}, {board[1][0], board[1][1]}};
            for (int i = 0; i < 3; i++) {
                temp = clockwise(temp);
                ret = isValidCharacter(temp);
                if (ret) {
                    break;
                }
            }
        }

        if (!ret) {
            char[][] temp = new char[][]{{board[0][0], board[0][1]}, {board[1][0], board[1][1]}};
            for (int i = 0; i < 3; i++) {
                temp = otherClockwise(temp);
                ret = isValidCharacter(temp);
                if (ret) {
                    break;
                }
            }
        }

        if (ret) {
            bw.write("YES\n");
        } else {
            bw.write("NO\n");
        }

        br.close();
        bw.close();
    }
}