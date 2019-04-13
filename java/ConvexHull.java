import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ConvexHull {

    public static void main(String[] args) throws IOException {
        List<long[]> points = loadPoints();
        sortPoints(points);
        List<long[]> convexHull = getConvexHull(points);
        double result = getConvexHullSize(convexHull);
        // Result with first and last points hanging
        System.out.println(points.get(0)[1] + result + points.get(points.size() - 1)[1]);
    }

    private static List<long[]> loadPoints() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int pointCount = Integer.valueOf(bf.readLine());

        List<long[]> points = new ArrayList<>();
        for (int i = 0; i < pointCount; i++) {
            long[] point = new long[2];

            String[] coordinates = bf.readLine().split(" ");

            point[0] = Long.valueOf(coordinates[0]);
            point[1] = Long.valueOf(coordinates[1]);

            points.add(point);
        }

        return points;
    }

    private static void sortPoints(List<long[]> points) {
        Collections.sort(points, new Comparator<long[]>() {
            @Override
            public int compare(long[] o1, long[] o2) {
                return Long.compare(o1[0], o2[0]);
            }
        });
    }

    private static List<long[]> getConvexHull(List<long[]> points) {
        List<long[]> convexHull = new ArrayList<>();

        Collections.reverse(points);
        for (long[] point : points) {
            while (convexHull.size() >= 2 &&
                    concaveAngle(convexHull.get(convexHull.size() - 2), convexHull.get(convexHull.size() - 1), point)) {
                convexHull.remove(convexHull.size() - 1);
            }

            convexHull.add(point);
        }

        return convexHull;
    }

    private static boolean concaveAngle(long[] a, long[] b, long[] c) {
        // (b.y - a.y)  / (b.x - a.x) >= (c.y - b.y) / (c.x - b.x)
        // (b.y - a.y) * (c.x - b.x) >= (c.y - b.y) * (b.x - a.x)
        return (b[1] - a[1]) * (c[0] - b[0]) >= (c[1] - b[1]) * (b[0] - a[0]);
    }


    private static double getConvexHullSize(List<long[]> convexHull) {
        double result = 0;

        for (int i = 1; i < convexHull.size(); i++) {
            // Pythagoras theorem: sqrt( a^2 + b^2 ) = c
            long[] a = convexHull.get(i - 1);
            long[] b = convexHull.get(i);

            long xLen = (b[0] - a[0]) * (b[0] - a[0]);
            long yLen = (b[1] - a[1]) * (b[1] - a[1]);

            result += Math.sqrt(xLen + yLen);
        }

        return result;
    }

}
