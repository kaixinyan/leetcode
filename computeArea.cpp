int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int area1 = (C - A) * (D - B);
        
        int area2 = (G - E) * (H - F);
        
        int areaOverlap;
        
        
        if (E >= C || A >= G || F >= D || B >= H || area1 == 0 || area2 == 0) return area1 + area2;
        
        else areaOverlap = (min(C,G) - max(A,E)) * (min(D,H) - max(B,F));
        
        return area1 + area2 - areaOverlap;
        
    }
