VERSION = 1.0

archive:
	-rm lifekeeper-*.tar.gz
	-rm -fr lifekeeper-$(VERSION)/*
	mkdir -p lifekeeper-$(VERSION)
	cp -frauv lifekeeper.c lifekeeper.1 lifekeeper-$(VERSION)
	tar cpvf lifekeeper-$(VERSION).tar lifekeeper-$(VERSION)
	gzip lifekeeper-$(VERSION).tar
	-rm -fr lifekeeper-$(VERSION)
