
    while(cin>>a>>b){
    	memset(dp,0,sizeof(0));
    	int la=strlen(a),lb=strlen(b);
    	for(int i=1;i<=la;i++)
			for(int j=1;j<=lb;j++){
    		dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
    		if(a[i-1]==b[j-1]&&dp[i][j]<dp[i-1][j-1]+1)dp[i][j]=dp[i-1][j-1]+1;
		}
		cout<<dp[la][lb]<<endl;
	}
