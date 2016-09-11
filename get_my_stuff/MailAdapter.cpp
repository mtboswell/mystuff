#ifndef MAILADAPTER_H
#define MAILADAPTER_H


class MailAdapter : public NodeInputAdapter
{
public:
    MailAdapter()

{}

signals:

public slots:
};

#endif // MAILADAPTER_H

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <mailutils/mailutils.h>

int
MailAdapter::mainLoop (const char * mailboxaddr)
{
  char *from;
  char *subject;
  mu_mailbox_t mbox;
  size_t msgno, total = 0;
  int status;

  /* Register the formats. */
  mu_register_all_mbox_formats ();

  status = mu_mailbox_create_default (&mbox, mailboxaddr);
  if (status != 0)
    {
      mu_error ("mu_mailbox_create: %s", mu_strerror (status));
      exit (EXIT_FAILURE);
    }

  status = mu_mailbox_open (mbox, MU_STREAM_READ);
  if (status != 0)
    {
      mu_error ("mu_mailbox_open: %s", mu_strerror (status));
      exit (EXIT_FAILURE);
    }

  mu_mailbox_messages_count (mbox, &total);

  for (msgno = 1; msgno <= total; msgno++)
    {
      mu_message_t msg;
      mu_header_t hdr;

      if ((status = mu_mailbox_get_message (mbox, msgno, &msg)) != 0
          || (status = mu_message_get_header (msg, &hdr)) != 0)
        {
          mu_error ("Error message: %s", mu_strerror (status));
          exit (EXIT_FAILURE);
        }

      if (mu_header_aget_value (hdr, MU_HEADER_FROM, &from))
        from = strdup ("(NO FROM)");

      if (mu_header_aget_value (hdr, MU_HEADER_SUBJECT, &subject))
        subject = strdup ("(NO SUBJECT)");

      printf ("%s\t%s\n", from, subject);
      free (from);
      free (subject);
    }

  status = mu_mailbox_close (mbox);
  if (status != 0)
    {
      mu_error ("mu_mailbox_close: %s", mu_strerror (status));
      exit (EXIT_FAILURE);
    }

  mu_mailbox_destroy (&mbox);
  return 0;
}

