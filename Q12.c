Q = queue of currProc
index = index of Q
p = currProc
if p is blocking for I/O:
save processing state to p.PCB
  Q.dequeue()
if index == 0:
        Q.enqueue(p)
 else:
queues[index-1].enqueue(p)
endif
elif p leaves voluntarily:
    save processing state to p.PCB
Q.dequeue()
  store (p.pid, index)
else:
    p.taskTime -= 1
    p.Qtime -= 1
 if quantum time finished (p.Qtime <= 0):
        save processing state to p.PCB
        Q.dequeue()

        if task not finished (p.taskTime > 0):
            queues[index+1].enqueue(p)
 else:
destroy(p)
endif
elif task finished (p.taskTime <= 0):
        Q.dequeue()
 destroy(p)
 else:
 pass
endif
endif
Second step:
for Q in queues:
  if Q is not empty:
    p = Q.peek()
    Current Proc = p
    send p to CPU
    break
  endif
end for
