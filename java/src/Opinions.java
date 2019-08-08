import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Opinions {

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int people = sc.nextInt();
        int instructions = sc.nextInt();

        int[] sameOpinion = new int[people + 1];
        int[] sameOpinionSize = new int[people + 1];

        int[] analyzed = new int[people + 1];
        int[] analyzedSize = new int[people + 1];

        for (int i = 0; i < sameOpinion.length; i++) {
            sameOpinion[i] = i;
            sameOpinionSize[i] = 1;

            analyzed[i] = i;
            analyzedSize[i] = 1;
        }

        for (int i = 0; i < instructions; i++) {
            String c = sc.next().trim();
            int a = sc.nextInt();
            int b = sc.nextInt();

            switch (c) {
                case "+":
                    if (addingAnalyzed(analyzed, a, b) && !addingAnalyzed(sameOpinion, a, b)) {
                        System.out.println("chyba");
                        break;
                    }

                    union(sameOpinion, sameOpinionSize, a, b);
                    union(analyzed, analyzedSize, a, b);
                    break;

                case "-":
                    if (addingAnalyzed(analyzed, a, b)) {
                        System.out.println("chyba");
                        break;
                    }

                    // TODO fix this shit:
                    //  - Invert and add
//                    union(sameOpinion, a, invertedB);
//                    union(analyzed, analyzedSize, a, b);
                    break;

                case "?":
                    if (!addingAnalyzed(analyzed, a, b)) {
                        System.out.println("neviem");
                    } else if (addingAnalyzed(sameOpinion, a, b)) {
                        System.out.println("ano");
                    } else {
                        System.out.println("nie");
                    }
                    break;
            }
        }
    }

    private static int find(int[] arr, int idx) {
        if (arr[idx] != idx) {
            arr[idx] = find(arr, arr[idx]);
        }
        return arr[idx];
    }

    private static boolean addingAnalyzed(int[] analyzed, int a, int b) {
        int analA = find(analyzed, a);
        int analB = find(analyzed, b);

        return analA == analB;
    }

    private static void union(int[] same, int[] size, int a, int b) {
        int rootA = find(same, a);
        int rootB = find(same, b);

        if (size[rootA] > size[rootB]) {
            size[rootA] += size[rootB];
            same[rootB] = rootA;
        } else {
            size[rootB] += size[rootA];
            same[rootA] = rootB;
        }
    }

}
