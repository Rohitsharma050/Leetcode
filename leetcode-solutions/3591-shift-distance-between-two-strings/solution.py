class Solution:
    def shiftDistance(self, s: str, t: str, nextCost: List[int], previousCost: List[int]) -> int:
        total_cost = 0
    
        for i in range(len(s)):
        # Calculate the indices of the characters in the alphabet (0-based)
            s_idx = ord(s[i]) - ord('a')
            t_idx = ord(t[i]) - ord('a')
        
        # Forward distance and cost
            forward_distance = (t_idx - s_idx) % 26
            forward_cost = sum(nextCost[(s_idx + j) % 26] for j in range(forward_distance))
        
        # Backward distance and cost
            backward_distance = (s_idx - t_idx) % 26
            backward_cost = sum(previousCost[(s_idx - j) % 26] for j in range(backward_distance))
        
        # Add the minimum cost of forward or backward shift
            total_cost += min(forward_cost, backward_cost)
    
        return total_cost
