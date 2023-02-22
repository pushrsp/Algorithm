 class Solution {
        private long gcd(long a, long b) {
            if (a % b == 0)
                return b;

            return gcd(b, a % b);
        }

        public long solution(int w, int h) {

            long area = (long) w * h;
            long gcd = gcd(w, h);


            return area - (((w / gcd) + (h / gcd) - 1) * gcd);
        }
    }