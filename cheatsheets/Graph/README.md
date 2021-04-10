#### Notes
- When doing bfs, dfs. Check `vis` next node immediately to reduce time/space complexity

```C++
while(!Q.empty()) {
	int cur_node = Q.front();
	Q.pop();

	// Check vis here
	vis[cur_node] = 1;

	for(int &d:dirs) {
		int next_node = cur_node + d;

		if(vis[next_node] == 0) {
			// Update
			...

			// Also check vis here to reduce BFS complexity
			vis[next_node] = 1;
			Q.push(next_node);
		}
	}
}
```



## 5_Flow_Dinic
<img src="./img/5_Flow_Dinic.jpg" alt="drawing" width="650"/>

## 6_biGraph_MaximumMatching_Dinic
<img src="./img/6_biGraph_MaximumMatching_Dinic.jpg" alt="drawing" width="650"/>
