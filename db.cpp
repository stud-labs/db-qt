#include "./db.hpp"
#include <QSqlDatabase>
#include <QProcess>
#include <iostream>
#include <cstdlib>

QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

QProcess ssh;

size_t portNo = 5432;

/*
 *     Settings settings; const Settings::SSH &ssh{settings.loadSSH()}; ssh_key key;
    int code = ssh_pki_import_privkey_file("key.ossh", ssh.password.toStdString().c_str(), NULL, NULL, &key);
    if(code != SSH_OK)
    {
        _logger->logOnce("Bad private key!");
        return false;
    }

    ssh_options_set(_ssh, SSH_OPTIONS_HOST, ssh.host.toStdString().c_str());
    code = ssh_connect(_ssh);
    if(code != SSH_OK)
    {
        _logger->logSshErrorOnce("Unable to connect to host!", _ssh);
        return false;
    }
    code = ssh_userauth_publickey(_ssh, ssh.login.toStdString().c_str(), key);
    if(code != SSH_AUTH_SUCCESS)
    {
        _logger->logSshErrorOnce("Unable to authorize!", _ssh);
        return false;
    }
    code = ssh_channel_open_forward(_channel, ssh.host.toStdString().c_str(), 22, "localhost", 3307);
    if(code != SSH_OK)
    {
        _logger->logSshErrorOnce("Unable to create ssh-channel!", _ssh);
        return false;
    }
 * */


bool SetupDatabaseConnection(QSqlDatabase db) {
  QString psw = std::getenv("DBPASSWD");
  ssh.start("ssh",
            {"-L", "5432:localhost:5432",
             "eugeneai@kuber.isclan.ru"});

  db.setHostName("localhost");
  db.setDatabaseName("test");
  db.setUserName("dbstudent");
  db.setPassword(psw);
  db.setPort(portNo);
  return db.open();
}



