Position BinarySearch( List L, ElementType X )
{
    ElementType min = 1;
    ElementType max = (*L).Last;
    ElementType mid = (min+max) /2;

    while(max>min)
    {
        if((*L).Data[mid]==X)
        {
            return mid;
        }
        else if((*L).Data[mid]>X)
        {
            max = mid;
            mid = (min+max)/2;
        }
        else if((*L).Data[mid]<X)
        {
            min = mid;
            mid = (min+max)/2;
        }
        if(mid+1==max)
        {
            if((*L).Data[mid]==X)
            {
                return mid;
            }
            else if((*L).Data[max]==X)
            {
                return max;
            }
            else
            {
                return NotFound;
            }
        }
    }

    return NotFound;
}