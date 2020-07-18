import * as Sentry from '@sentry/react';

function init() {
  Sentry.init({
    dsn:
      'https://c6b656da3f5248ac9310d07afa5032e1@o422192.ingest.sentry.io/5345292',
  });
}

function log(error) {
  Sentry.captureException(error)
}

export default {
  init,
  log,
};
