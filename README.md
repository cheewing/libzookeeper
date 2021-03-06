PHP Libzookeeper Extension
----

[![Build Status](https://img.shields.io/travis/Timandes/libzookeeper/master.svg?style=flat-square)](https://travis-ci.org/Timandes/libzookeeper)
[![Coverage Status](https://coveralls.io/repos/Timandes/libzookeeper/badge.svg?branch=master&service=github)](https://coveralls.io/github/Timandes/libzookeeper?branch=master)


Communicate with Zookeeper using PHP.

Requirements
====

* [Zookeeper C Client](https://zookeeper.apache.org/) (v3.4, v3.5)
* [PHP](http://www.php.net/) (v5.3, v5.4, v7.0)

Install
====

    $ phpize
    $ ./configure --with-libzookeeper=/path/to/zookeeper-c-client
    $ make
    $ make install

Examples
====

    <?php
    $zc = new ZookeeperClient();
    $zc->connect('localhost:2181');
    var_dump($zc->get('/zookeeper'));
    ?>

[More](http://libzookeeper.readthedocs.org/en/latest/examples.html)

Reference
====

[View On RTFD](http://libzookeeper.readthedocs.org/en/latest/index.html)