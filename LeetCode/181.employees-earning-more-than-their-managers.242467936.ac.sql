select e.name as employee from employee e, employee m where e.managerid=m.id and e.salary>m.salary;

