# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        def find_len(head: ListNode) -> int:
            count = 0
            while head:
                head = head.next
                count += 1
            return count

        def find_mid(head: ListNode, size:int) -> ListNode:
            
            size=size/2
            size-=1
            s=head
            while s and size:
                s=s.next
                size-=1
            return s
        
        def check(head:ListNode)->bool:
            val=-sys.maxsize
            while head:
                if head.val<val:
                    return false
                val=head.val
            return True
        
        def merge(head: ListNode, size:int):
            
            h1 = head
            mid = find_mid(head,size)
            # print(size)
            if not mid:
                return [h1,h1]
            h2 = mid.next
            mid.next = None
            # print(h1)
            # print(h2)
            if (not h1) and (not h2):
                return [h1, h1]
            if not h1:
                return [h2, h2]
            if not h2:
                return [h1, h1]
            
            if h1.val < h2.val:
                new_head, new_tail = h1, h1
                h1 = h1.next
            else:
                new_head, new_tail = h2, h2
                h2 = h2.next
        
            while h1 and h2:
                if h1.val < h2.val:
                    new_tail.next = h1
                    new_tail = h1
                    h1 = h1.next
                else:
                    new_tail.next = h2
                    new_tail = h2
                    h2 = h2.next
            if h1:
                new_tail.next = h1
            if h2:
                new_tail.next = h2
            while new_tail.next:
                new_tail=new_tail.next
            # print(new_head, new_tail)
            return [new_head, new_tail]

        len = find_len(head)
        if len < 2:
            return head
        size = 2
        while size<=2*len:
            tempHead = head
            ptr = tempHead
            count = 1
            resH, resT = None, None
            while ptr:
                if count == size:
                    temp = ptr.next
                    ptr.next = None
                    new_head, new_tail = merge(tempHead,size)
                    if resH == None:
                        resH = new_head
                    if resT != None:
                        resT.next = new_head
                    resT = new_tail
                    tempHead = temp
                    count = 1
                    ptr = tempHead
                else:
                    ptr=ptr.next
                    count += 1
                
            if count > 1:
                new_head, new_tail = merge(tempHead,size)
                if resH == None:
                    resH = new_head
                if resT != None:
                    resT.next = new_head
                resT = new_tail
            # print("LL:")
            # print(resH)
            head=resH
            size*=2
            # if check(head):
            #     break
        return resH