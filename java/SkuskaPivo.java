import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class SkuskaPivo {

    public static void main(String[] args) {
        // Nice api of scanner with performance benefits of Buffered Reader
        // This works even on problems with large input sets
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int sets = sc.nextInt();
        for (int i = 0; i < sets; i++) {
            int phases = sc.nextInt();

            int[] machineAPhases = loadArray(phases, sc);
            int[] machineBPhases = loadArray(phases, sc);

            // There is 1 less transition than phases, since we cannot transition without performing the first phase
            int[] machineATransitions = loadArray(phases - 1, sc);
            int[] machineBTransitions = loadArray(phases - 1, sc);

            // Greedy solution to finding the minimal time:
            // For each phase remember the minimal time that is needed to perform it, while ending up on each machine
            int minEndingOnMachineA = machineAPhases[0];
            int minEndingOnMachineB = machineBPhases[0];

            // Starting with the first phase
            for (int phase = 1; phase < phases; phase++) {
                int timeForPhaseOnMachineA = Math.min(
                        minEndingOnMachineA, // Going from A
                        minEndingOnMachineB + machineBTransitions[phase - 1] // Transitioning from B to A
                ) + machineAPhases[phase];

                int timeForPhaseOnMachineB = Math.min(
                        minEndingOnMachineB,
                        minEndingOnMachineA + machineATransitions[phase - 1]
                ) + machineBPhases[phase];

                // Change to new values, once the old ones can be discarded
                minEndingOnMachineA = timeForPhaseOnMachineA;
                minEndingOnMachineB = timeForPhaseOnMachineB;
            }

            // Result is the minimum of time required to end up on last phase for each machine
            int result = Math.min(minEndingOnMachineA, minEndingOnMachineB);
            System.out.println(result);
        }
    }

    private static int[] loadArray(int count, Scanner sc) {
        int[] phases = new int[count];

        for (int i = 0; i < phases.length; i++) {
            phases[i] = sc.nextInt();
        }

        return phases;
    }

}
