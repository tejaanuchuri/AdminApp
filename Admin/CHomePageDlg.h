#pragma once


// CHomePageDlg dialog

class CHomePageDlg : public CDialog
{
	DECLARE_DYNAMIC(CHomePageDlg)

public:
	CHomePageDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHomePageDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADMIN_HOME_PAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void ResetListControl();
	void m_ResetListControl();
	void emp_data_load();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl emp_list;
	afx_msg void OnBnClickedButtonFetchRecords();
	virtual BOOL OnInitDialog();
	CString emp_title;
	CString emp_firstname;
	CString emp_age;
	CString emp_gender;
	CString emp_email;
	COleDateTime emp_datebirth;
	CString emp_phonenumber;
	CString emp_address;
	CString emp_salary;
	CString emp_jobtitle;
	CComboBox cemp_title;
	CStatic c_title;
	CString uemp_no;
	CString change_operation;
	afx_msg void OnBnClickedButtonSwitchingOperatons();
	CStatic cinsert_title;
	CStatic CSAge;
	CEdit CAge;
	CStatic CSFirstName;
	CEdit CFirstName;
	CStatic CSLastName;
	CEdit CLastName;
	CStatic CSGender;
	CComboBox CGender;
	CStatic CSEmail;
	CEdit CEmail;
	CStatic CSPhoneNumber;
	CEdit CPhoneNumber;
	CStatic CSAddress;
	CEdit CAddress;
	CStatic CSDateBirth;
	CMonthCalCtrl CBirthDate;
	CStatic CSJobTitle;
	CComboBox CJobTitle;
	CStatic CSSalary;
	CEdit CSalary;
	CStatic CSHireDate;
	CMonthCalCtrl CHireDate;
	CButton Cinsert;
	CStatic CSUpdateRecord;
	CStatic CSEmpNo;
	CEdit CEmpNumber;
	CStatic CSChooseField;
	CComboBox CChooseField;
	CString UChooseField;
	CStatic CDUpdataField;
	CEdit CUpdateField;
	CButton CBUpdate;
	CStatic CSDeleteEmployee;
	CStatic CSEnterEmployeeNumber;
	CString DEmployeeNumber;
	CButton CBDelete;
	CEdit CSEnterEmpNumber;
	CStatic CSSearchEmpRecord;
	CStatic CSChooseFieldSearch;
	CString CChooseFieldSearch;
	CStatic CSEnterEmployeeDetails;
	CEdit CEnterEmployeeDetails;
	CString CEmpSearchDetails;
	CButton CBSearch;
	CComboBox CChooseFeildSearchValue;
	CButton CBFetchSearch;
	afx_msg void OnBnClickedButtonInsertEmployee();
	CString emp_lastname;
	COleDateTime emp_HireDate;
	CMonthCalCtrl CEmp_Hiredate;
	COleDateTime employee_hiredate;
	afx_msg void OnBnClickedButtonDeleteEmployeeRecord();
	afx_msg void OnBnClickedButtonSearchEmployeeRecord();
	afx_msg void OnBnClickedButtonUpdateEmployeeRecord();
	CString Update_Field_Value;
	afx_msg void OnCbnSelchangeComboChooseField();
	CMonthCalCtrl CUpdateDate;
	COleDateTime UpdateDate;
	CListCtrl m_Search_list;
	afx_msg void OnCbnDropdownComboChooseField();
	afx_msg void OnCbnEditupdateComboChooseField();
	afx_msg void OnCbnEditchangeComboChooseField();
	afx_msg void OnStnClickedStaticUpdateFiled();
	afx_msg void OnBnClickedButtonSetTheColumn();
	afx_msg void OnStnClickedStaticEnterEmpDetails();
};
