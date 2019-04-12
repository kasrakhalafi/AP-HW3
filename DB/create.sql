CREATE TABLE User (
  id SERIAL,
  telegram_id TEXT PRIMARY KEY,
  phone TEXT NOT NULL,
  email TEXT,
  password text,
  first_name TEXT,
  last_name TEXT,
  verification_code INTEGER,
  profile_picture_url INTEGER,
  created_at TIMESTAMP,
  updated_at TIMESTAMP
);

create table BlockUser(
  blocker_user_id TEXT,
  blocked_user_id TEXT,
  created_at TIMESTAMP NOT NULL ,

  FOREIGN KEY (blocked_user_id) REFERENCES User(telegram_id) ,
  FOREIGN KEY (blocker_user_id) REFERENCES User(telegram_id)
);

create table Massage(
  id SERIAL PRIMARY KEY,
  sender_id text NOT NULL,
  receiver_id TEXT NOT NULL,
  message_type TEXT,
  message_text text,
  created_at TIMESTAMP not NULL,
  updated_at TIMESTAMP NOT NULL,

  FOREIGN KEY (sender_id) REFERENCES User(telegram_id) ,
  FOREIGN KEY (receiver_id) REFERENCES User(telegram_id)
);


create table Channel(
  id SERIAL,
  telegram_id TEXT PRIMARY KEY,
  title TEXT,
  info TEXT,
  creator_id TEXT,
  created_at TIMESTAMP,
  updated_at TIMESTAMP,

  FOREIGN key (creator_id) REFERENCES User(telegram_id)
);

create table Group(
  id SERIAL PRIMARY KEY,
  creator_id TEXT,
  title TEXT,
  join_url TEXT,
  created_at TIMESTAMP,
  updated_at TIMESTAMP,

  FOREIGN KEY (creator_id) REFERENCES User(telegram_id)
);

create table GroupMessage(
  id SERIAL PRIMARY KEY,
  group_id text PRIMARY KEY,
  sender_id text,
  message_type text,
  message_text text,
  created_at TIMESTAMP,
  updated_at TIMESTAMP,

  FOREIGN KEY (sender_id) REFERENCES User(telegram_id)

);

create table ChannelMessage(
  id SERIAL PRIMARY KEY,
  channel_id text PRIMARY KEY ,
  message_type TEXT,
  message_text TEXT,
  created_at TIMESTAMP,
  updated_at TIMESTAMP
);


create table MessageAttachment(
  message_id SERIAL PRIMARY KEY,
  attachment_url text,
  attachment_thumb_url text,

  FOREIGN KEY(message_id) REFERENCES Message(id)
);


CREATE table GroupMessage_attachment(
  message_id SERIAL,
  attachment_url TEXT,
  attachment_thumb_url text ,

  FOREIGN KEY (message_id) REFERENCES GroupMessage(id)
);

create table ChannelMessageAttachment(
  message_id SERIAL,
  attachment_url text,
  attachment_thumb_url text ,

  FOREIGN KEY (message_id) REFERENCES ChannelMessage(id)
);

create table ChannelMembership(
  user_id text,
  channel_id text,
  created_at TIMESTAMP ,

  FOREIGN KEY (user_id) REFERENCES User(telegram_id) ,
  FOREIGN KEY (channel_id) REFERENCES Channel(telegram_id)
);

create table GroupMembership(
  user_id text,
  group_id INTEGER,
  created_at TIMESTAMP ,

  FOREIGN KEY (user_id) REFERENCES User(telegram_id) ,
  FOREIGN KEY (group_id) REFERENCES Group(id)
);
