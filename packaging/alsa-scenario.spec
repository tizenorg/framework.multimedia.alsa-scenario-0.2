Name:       alsa-scenario
Summary:    ALSA Scenario pkg
Version:    0.2.7
Release:    0
Group:      LGPL-2.0+
License:    LGPL-2.0+
Source0:    %{name}-%{version}.tar.gz
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(alsa)
BuildRequires:  pkgconfig(dlog)


%description
ALSA Scenario package



%package devel
Summary:    ALSA Scenario pkg (devel)
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
ALSA Scenario package (devel)


%prep
%setup -q


%build
%autogen
cp -f /usr/share/libtool/config/config.guess %{_builddir}/%{name}-%{version}/
cp -f /usr/share/libtool/config/config.sub %{_builddir}/%{name}-%{version}/
%configure --disable-static --enable-dlog
make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}/usr/share/license
cp LICENSE.LGPLv2 %{buildroot}/usr/share/license/%{name}


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig





%files
%manifest alsa-scenario.manifest
/usr/lib/libascenario-0.2.so.*
/usr/share/license/%{name}

%files devel
/usr/include/alsa/*.h
/usr/lib/libascenario.so
/usr/lib/pkgconfig/libascenario.pc

