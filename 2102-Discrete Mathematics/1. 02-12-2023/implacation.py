from prettytable import PrettyTable

table=PrettyTable()

table.field_names =[" p "," q "," !p "," !q "," p /\ q "," p \/ q "," p -> q "," p <-> q "]

for p in range(0,2):
    for q in range(0,2):
        table.add_row([
            bool(p), # Just p
            bool(q), # Just q
            bool(not p), # not p
            bool(not q), # not q
            bool(p and q), # p /\ q
            bool(p or q), # p \/ q
            bool((not p) or (p and q)), # p->q (p imples q)
            bool(((not p) or (p and q)) and ((not q) or (q and p)))]) # (p->q) /\ (q->p)

print(table)