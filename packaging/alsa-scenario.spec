Name:             alsa-scenario
Summary:          ALSA Scenario pkg
Version:          0.2.1
Release:          0
Group:            Multimedia/Audio FW
License:          LGPL-2.0+
Source0:          %{name}-%{version}.tar.gz
Source1001:       packaging/alsa-scenario.manifest 
Requires(post):   /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:    pkgconfig(alsa)
BuildRequires:    pkgconfig

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
cp %{SOURCE1001} .
cp -f %{_datadir}/libtool/config/config.guess %{_builddir}/%{name}-%{version}/
cp -f %{_datadir}/libtool/config/config.sub %{_builddir}/%{name}-%{version}/
%reconfigure --disable-static
%__make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%make_install


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig


%files
%{_libdir}/libascenario-0.2.so.*

%files devel
%{_includedir}/alsa/*.h
%{_libdir}/libascenario.so
%{_libdir}/pkgconfig/libascenario.pc
