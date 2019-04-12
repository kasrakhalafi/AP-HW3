--Q1
select * from user where phone = '09120000001';

--Q2
update User
  set email= 'apstudent2019@gmail.com'
  where phone= '09120000001';

--Q3
select distinct u.*
FROM User u,ChannelMembership c
where u.phone ='09120000001' and u.telegram_id = c.user_id;

--Q4
select distinct c.*
FROM ChannelMembership c
where c.channel_id='aut_ap_2019'

--Q5
select user.email
FROM User
where User.phone LIKE '%0935%';

--Q6
select BlockUser.blocked_user_id
FROM BlockUser,User
where User.phone='09120000001' and User.telegram_id = BlockUser.blocker_user_id;

--Q7
select cm.creator_id
FROM ChannelMembership c,user u,ChannelMessage cm
where u.email='apstudent2019@gmail.com' and distinct count(c.user_id)>3;

--Q8
select Message.*
from Message
where message.sender_id='amir.jahanshahi' and message.receiver_id='‫‪sHDiV4RHs‬‬'
OR message.receiver_id='amir.jahanshahi' and message.sender_id='‫‪sHDiV4RHs‬‬';
