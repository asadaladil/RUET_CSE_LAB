from prettytable import PrettyTable

table=PrettyTable()
# p->(q && r) , (p->q) && r 
table.field_names=["p","q","r","q /\ r","p->q","p->(q /\ r)","(p->q) /\ r"]

check="is "
for p in range(0,2):
    for q in range(0,2):
        for r in range(0,2):
            table.add_row([
                bool(p),
                bool(q),
                bool(r),
                bool(q and r),
                bool(not p or q),
                bool(not p or (q and r)),
                bool((not p or q) and r)
                ])
            a=not p or (q and r)
            b=(not p or q) and r
            if a!=b:
                check="is not ";

print(table)
print("From Truth Table it can be said that p->(q /\ r) and (p->q) /\ r "+check+"EQUIVALENT\n")
            
