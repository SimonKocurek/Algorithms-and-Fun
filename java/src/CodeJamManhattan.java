import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CodeJamManhattan {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int sets = sc.nextInt();

        for (int i = 1; i <= sets; i++) {
            System.out.print("Case #" + i + ": ");

            int people = sc.nextInt();
            int q = sc.nextInt() + 1;

            int[] yAdded = new int[q];
            int[] xAdded = new int[q];

            for (int j = 0; j < people; j++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                String c = sc.next().trim();

                switch (c) {
                    case "N":
                        yAdded[y + 1]++;
                        break;
                    case "S":
                        yAdded[0]++;
                        yAdded[y]--;
                        break;
                    case "W":
                        xAdded[0]++;
                        xAdded[x]--;
                        break;
                    case "E":
                        xAdded[x + 1]++;
                        break;
                }
            }

            int resX = 0;
            int xMax = 0;

            int xGot = 0;
            for (int x = 0; x < q; x++) {
                xGot += xAdded[x];
                if (xGot > xMax) {
                    xMax = xGot;
                    resX = x;
                }
            }

            int resY = 0;
            int yMax = 0;

            int yGot = 0;
            for (int y = 0; y < q; y++) {
                yGot += yAdded[y];

                if (yGot > yMax) {
                    yMax = yGot;
                    resY = y;
                }
            }

            System.out.println(resX + " " + resY);
        }
    }

}
