int queue[MAX];

int degrees_of_separation(int start, int end) {
    int visited[MAX] = {0};
    int distance[MAX] = {0};

    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear) {
        int current = queue[front++];

        for(int i = 0; i < MAX; i++) {
            if(graph[current][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                queue[rear++] = i;

                if(i == end)
                    return distance[i];
            }
        }
    }

    return -1;
}