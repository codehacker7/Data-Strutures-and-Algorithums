bool isCyclicDFSHelper(T src, unordered_map<T, bool> &visited,
	                       unordered_map<T, bool> &currentPath) {
		currentPath[src] = true;
		visited[src] = true; // Visit kar lia toh theek hai
		// isko backtrack nahi kroge
		// ab baaki neighbours pr jaakar dekho
		for (auto neighbours : adj[src]) {
			if (currentPath[neighbours]) {
				return true;
			}
			else if (!visited[neighbours]) {
				bool ans = isCyclicDFSHelper(neighbours, visited, currentPath);
				if (ans == true) {
					return true;
				}
			}
		}

		// Agar kisi bhi neighbour se dobara src par nhi aaya mei currentPath common
		// karke matlb cycle nhi milli
		currentPath[src] = false;
		return false;
	}

	bool isCyclicDFS() {
		unordered_map<T, bool> visited;
		unordered_map<T, bool> currentPath;
		for (auto p : adj) {
			if (!visited[p.first]) {
				bool ans = isCyclicDFSHelper(p.first, visited, currentPath);
				if (ans) return true;

			}

		}

		return false;
	}
};