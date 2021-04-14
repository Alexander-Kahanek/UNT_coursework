# using python 3.9
################
# algorithm:
# recursively divides left section first
# divide until len is either 1 or 2
# recursively merge small pieces, until left side is sorted
# repeat with right side
# merge final left and right splits
# return final list

def merge_lists(left, right):
    '''
    function merges left and right lists that are given from min to max.

    input: left, right | need to be a list of left and right split to merge
    output: a single list, sorted from min to max
    '''
    # print(f'inside merge_lists with left: {left} and right: {right}')

    # counters for numbers added to merged_list, which is the final ordered list
    left_cnt, right_cnt, merged_list = 0, 0, []

    while left_cnt < len(left) and right_cnt < len(right):
        # until function sees all numbers of one list
        if left[left_cnt] < right[right_cnt]:
            # then left number is first
            merged_list.append(left[left_cnt])  # add number to list
            left_cnt += 1  # used number, add counter
        else:
            # left number was bigger, add right number
            merged_list.append(right[right_cnt])  # add number to list
            right_cnt += 1  # used number, add counter

    # print(f'inside while loop: {merged_list}')

    # while loops misses max numbers when one list finishes
    # so, add left over list from left and right lsits
    merged_list.extend(left[left_cnt:])
    merged_list.extend(right[right_cnt:])

    # print(f'leaving merge_lists with: {merged_list}, lcnt: {left_cnt}, rcnt: {right_cnt}')
    return merged_list


def mergeSort(alist):
    '''
    function recursively divides alist, then merges each section until complete.

    input: alist | a sortable list, ie, [3,1,2], ['a', 'b', 'c']
    output: a fully sorted list from min to max value
    '''
    # print(f'inside mergeSort with {alist}')

    if len(alist) <= 1:  # base case, no sort needed
        return alist

    # divide list length in half to find split
    split = len(alist) // 2  # floor division
    # recursive calls
    left = mergeSort(alist[:split])
    right = mergeSort(alist[split:])

    return merge_lists(left, right)


print('*****************************************************')

# problem statement
alist = [54, 26, 93, 17, 77, 31, 44, 55, 20]
print(f'** problem statement: {mergeSort(alist)}')

# odd length list case
print(f'odd length case: {mergeSort([9961, 14135, 52357, 12341, 0])}')

# even length list case
print(f'even length case: {mergeSort([3, 0, 12, 67])}')

# decimals and negatives case
l = [0.00004, -11, 0.25913651, 0.00000000000000000009]
print(f'decimals and negatives case: {mergeSort(l)}')

# repeat numbers case
print(f'repeat numbers case: {mergeSort([2,5,3,0,7,0,86,125,85,23,7,2,96,2])}')

# tuple case
print(f'tuple case: {mergeSort((3,1,90,59,197))}')

# character case
print(f'character case: {mergeSort(["a", "q", "c", "z", "e"])}')

# string case
print(f'string case: {mergeSort("hello world")}')

# single number list case
print(f'single number list case: {mergeSort([12])}')

# empty list case
print(f'empty list case: {mergeSort([])}')
