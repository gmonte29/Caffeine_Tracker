

/*creating user account database*/
CREATE TABLE [User](
    [UserID] INTEGER NOT NULL,
    [UserName] TEXT UNIQUE NOT NULL,


    /*primary key required for database, unique for each user*/
    PRIMARY KEY ([UserID])
);