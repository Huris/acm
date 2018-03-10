

二叉堆
    1)	二叉堆是一种支持插入,删除,查询最值的数据结构。
    2)	它其实是一棵满足“堆性质”的完全二叉树,树上的每个结点带有一个权值。
    3)	大根堆:树中任意一个结点的权值都小于等于其父亲结点的权值
        小根堆:树中任意一个结点的权值都大于等于其父亲结点的权值
    4)	根据完全二叉树的性质,我们可以采用层次序列的存储方式,直接用一个数组保存二叉堆
        层次序列存储方式,就是逐层从左到右为树中的结点依次编号,把此编号作为结点在数组中存储的位置(下标)。
    5)	在这种存储方式中,父亲结点编号等于子节点编号除以2,
        左子节点编号等于父亲结点编号乘以2,
        右子节点编号等于父亲结点编号乘以2加1(所有下标从1开始)
    6)	操作
        a)	Insert
          i)	Insert(x)操作向二叉堆中插入一个带有权值为x的新结点,我们把这个新结点直接放在存储二叉堆的数组末尾,
              然后通过交换的方式向上调整,直至满足堆性质,其时间复杂度为堆的深度,即O(logn)
          ii)	代码
            int heap[100010],n;
            void up(int p)  //向上调整
            {
                while(p>1)
                {
                    if(heap[p]>heap[p/2])
                    {
                        swap(heap[p],heap[p/2]);
                        p/=2;
                        }
                    else break;
                    }
                }
           void ins(int x)
           {
                heap[++n]=x;
                up(n);
           }
        b)	GetTop
            GetTop操作返回二叉堆的堆顶权值,即最大值heap[1],复杂的O(1)
            int gettop()
            {
                return heap[1];
            }
        c)	Extract 
            Extract操作把堆顶从二叉堆中移除,我们把堆顶heap[1]与存储在数组末尾的结点heap[n]交换,
            然后移除数组末尾结点(令n减小1),最后把堆顶通过交换的方式向下调整,直至满足堆性质。
            其时间复杂度为堆的深度,即O(logn)
            void down(int p)
            {
                int s=p*2;
                while(s<=n) 
                {
                    if(s<n&&heap[s]<heap[s+1])s++;
                    if(heap[p]<heap[s])
                    {
                        swap(heap[p],heap[s]);
                        p=s;s=p*2;
                    }
                    else break;
                }
            }
            void extract()
            {
                heap[1]=heap[n--];
                down(1);
            }
            d)	Remove
                Remove(p)操作把存储在数组下标p位置的结点从二叉堆中删除,
                与extract相似,我们先把heap[p]与heap[n]交换,然后令n减1,
                注意此时heap[p]既有可能需要向下调整,也有可能向上调整,需要分别进行检查和处理,时间复杂度为O(logn)
                void remove(int p)
                {
                    heap[p]=heap[n--];
                    up(p);down(p);
                    }
