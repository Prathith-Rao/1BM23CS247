int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
    int sum_a = 0, score_a = 0;
    int sum_b = 0, score_b = 0;
    int max_score = 0;

    for (int i = 0; i < a_count; i++) {
        if (sum_a + a[i] > maxSum) break;
        sum_a += a[i];
        score_a++;
    }

    max_score = score_a; 
    for (int j = 0; j < b_count; j++) {
        sum_b += b[j];
        score_b++;

        while (sum_a + sum_b > maxSum && score_a > 0) {
            sum_a -= a[score_a - 1];
            score_a--;
        }

        if (sum_a + sum_b <= maxSum) {
            int current_score = score_a + score_b;
            if (current_score > max_score) {
                max_score = current_score;
            }
        } else {
            break; 
        }
    }

    return max_score;
}
