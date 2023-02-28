void qs(int Ls[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = pivot(Ls, lo, hi);
        p = part(Ls, lo, hi, p);
        qs(Ls, lo, p - 1);
        qs(Ls, p + 1, hi);
    }
}