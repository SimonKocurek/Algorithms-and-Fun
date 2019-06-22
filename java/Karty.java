import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Stack;

public class Karty {

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int cards = sc.nextInt();
        int[] card = new int[cards];
        for (int i = 0; i < cards; i++) {
            card[i] = sc.nextInt();
        }

        // For each card we precompute how many cards are weaker when we go in each direction
        int[] weakerToTheLeft = new int[cards];
        int[] weakerToTheRight = new int[cards];

        // We remember how up to how many cards we can go back
        Stack<Integer> got = new Stack<>();
        Stack<Integer> gotOnIndex = new Stack<>();
        for (int i = 0; i < cards; i++) {
            int weakerCards = 0;

            while (!got.isEmpty() && card[i] >= got.peek()) {
                got.pop();
                int weakerCardIndex = gotOnIndex.pop();

                // There are as many weaker cards as there are weaker cards from the weaker card
                // and cards up to the weaker card
                weakerCards = weakerToTheLeft[weakerCardIndex] + (i - weakerCardIndex);
            }

            weakerToTheLeft[i] = weakerCards;
            got.push(card[i]);
            gotOnIndex.push(i);
        }

        // Instead of creating new stack we can just empty the current one
        // this might save us some allocations
        got.clear();
        gotOnIndex.clear();
        // We go in opposite direction
        for (int i = cards - 1; i >= 0; i--) {
            int weakerCards = 0;

            while (!got.isEmpty() && card[i] >= got.peek()) {
                got.pop();
                int weakerCardIndex = gotOnIndex.pop();

                // i is now larger than weakerCardIndex
                weakerCards = weakerToTheRight[weakerCardIndex] + (weakerCardIndex - i);
            }

            weakerToTheRight[i] = weakerCards;
            got.push(card[i]);
            gotOnIndex.push(i);
        }

        // Print result
        for (int i = 0; i < cards; i++) {
            if (weakerToTheLeft[i] > weakerToTheRight[i]) {
                System.out.print("<");
            } else if (weakerToTheLeft[i] < weakerToTheRight[i]) {
                System.out.print(">");
            } else {
                System.out.print("=");
            }
        }
        System.out.println();
    }

}
