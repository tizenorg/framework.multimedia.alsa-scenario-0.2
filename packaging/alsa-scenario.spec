Name:       alsa-scenario
Summary:    ALSA Scenario pkg
Version: 0.2.1
Release:    13
Group:      Multimedia/Audio
License:    LGPLv2+
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(alsa)

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
cp -f /usr/share/libtool/config/config.guess %{_builddir}/%{name}-%{version}/
cp -f /usr/share/libtool/config/config.sub %{_builddir}/%{name}-%{version}/
%configure --disable-static
make %{?jobs:-j%jobs}

%install
%make_install

mkdir -p %{buildroot}/usr/share/license
cp COPYING %{buildroot}/usr/share/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest alsa-scenario.manifest
%{_libdir}/libascenario-0.2.so.*
/usr/share/license/%{name}

%files devel
%{_includedir}/alsa/*.h
%{_libdir}/libascenario.so
%{_libdir}/pkgconfig/libascenario.pc

