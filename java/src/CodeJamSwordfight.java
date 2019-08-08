import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class CodeJamSwordfight {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int sets = sc.nextInt();

        for (int i = 1; i <= sets; i++) {
            System.out.print("Case #" + i + ": ");

            int swords = sc.nextInt();
            int diff = sc.nextInt();

            int[][] c = new int[swords][2];
            int[] d = new int[swords];
            List<int[]> dSorted = new ArrayList<>(swords);

            for (int j = 0; j < swords; j++) {
                c[j][0] = sc.nextInt();
                c[j][1] = j;
            }
            for (int j = 0; j < swords; j++) {
                d[j] = sc.nextInt();
                dSorted.add(new int[]{d[j], j});
            }

            Arrays.sort(c, Comparator.comparingInt(o -> o[0]));
            dSorted.sort((o1, o2) -> {
                if (o1[0] == o2[0]) {
                    return Integer.compare(o1[1], o2[1]);
                } else {
                    return Integer.compare(o1[0], o2[0]);
                }
            });

            int result = 0;
            for (int start = 0; start < swords; start++) {
                int idx = c[start][1];
                if (idx < start) {
                    continue;
                }

                int found = Collections.binarySearch(dSorted, c[start][0], (o1, o2) -> {
                    int[] a = (int[]) o1;
                    int[] b = (int[]) o2;
                    if (a[0] == b[0]) {
                        return Integer.compare(b[1], a[1]);
                    } else {
                        return Integer.compare(a[0], b[0]);
                    }
                });

//                if (found < 0) {
//                    continue;
//                }
//
//                int[] ints = dSorted.get(found);

                int dMax = 0;
                for (int end = idx; end >= 0; end--) {
                    dMax = Math.max(dMax, d[end]);

                    if (Math.abs(c[start][0] - dMax) <= diff) {
                        result++;

                    } else if (dMax > c[start][0]) {
                        break;
                    }
                }
            }

            System.out.println(result);
        }
    }

}
