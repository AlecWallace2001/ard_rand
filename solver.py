import random

def reset():
    return {'a':0,'b':0,'c':0,'d':0,'e':0}

def press(state, button):
    res_d = {}
    for i in state.keys():
        if state[i]+button[i] == 2:
            res_d[i]=0
        else:
            res_d[i]= state[i]+button[i]
    return res_d

def iterate_bi(cycle):
    out = []
    cycle.reverse()
    up = True
    for i in cycle:
        if up:
            if i+1==3:
                out.append(0)
            else:
                out.append(i+1)
                up=False
        else:
            out.append(i)
    out.reverse()
    return out

def iterate_tri(cycle):
    out = []
    cycle.reverse()
    up = True
    for i in cycle:
        if up:
            if i+1==3:
                out.append(0)
            else:
                out.append(i+1)
                up=False
        else:
            out.append(i)
    out.reverse()
    return out

def setting(a,b,c,d,e):
    return {'a':int(a),'b':int(b),'c':int(c),'d':int(d),'e':int(e)}

def start_set():
    return setting(*list(str(str(bin(random.randint(1,30)))[2:]).zfill(5)))

def solving():
    button=[[],[],[]]
    solution = {'a':1,'b':1,'c':1,'d':1,'e':1}
    state = reset()
    for i in range(3):
        for j in range(3):
            print(i,j)
            button[i].append(start_set())
    button[0].append(0)
    button[1].append(0)
    button[2].append(0)
    cycle = [0,0,0,0,0,0,0,0,0,0]
    while cycle!=[2,2,2,2,2,2,2,2,2,2]:
        print(cycle)
        state = reset()
        button[0][3]=0
        button[1][3]=0
        button[2][3]=0
        print('Starting', state)
        for i in cycle:
            state = press(state,button[i][button[i][3]])
            print(state,button[i][button[i][3]])
            if button[i][3]+1==3:
                button[i][3] = 0
            else:
                button[i][3] = button[i][3]+1
            if state == solution:
                return button, cycle
        cycle = iterate_tri(cycle)
    return solving()
    
    
